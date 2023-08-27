#include "s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int success = Parce(str, format, args);
  va_end(args);
  return success;
}

int Parce(const char *str, const char *format, va_list args) {
  const char *beginning = str;
  int success = 0;
  while (*format && *str) {
    if (*format == '%') {
      specifier_s *specifier = ParceSpecifier(&format);
      success += AssignValues(beginning, &str, args, specifier);
      free(specifier);
      str--;
    }
    format++;
    str++;
  }
  return success;
}

int AssignValues(const char *beginning, const char **str, va_list args,
                 specifier_s *specifier) {
  int success = specifier->astrix ? 0 : 1;
  char c = specifier->type;
  switch (c) {
    case 'c':
      AssignC(str, args, specifier);
      break;
    case 'd':
      AssignD(str, args, specifier);
      break;
    case 'i':
      AssignI(str, args, specifier);
      break;
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G':
      AssignF(str, args, specifier);
      break;
    case 'o':
      AssignO(str, args, specifier);
      break;
    case 's':
      AssignS(str, args, specifier);
      break;
    case 'u':
      AssignU(str, args, specifier);
      break;
    case 'x':
    case 'X':
      AssignX(str, args, specifier);
      break;
    case 'p':
      AssignP(str, args, specifier);
      break;
    case 'n':
      if (!specifier->astrix) *va_arg(args, int *) = *str - beginning;
      break;

    default:
      success = 0;
      break;
  }
  return success;
}

specifier_s *ParceSpecifier(const char **format) {
  specifier_s *specifier = InitSpecifier();
  (*format)++;
  if (**format == '*') {
    specifier->astrix = 1;
    (*format)++;
  }
  if (IsDigit(**format)) {
    specifier->width = 0;
    WidthCheck(specifier, format);
  }
  if (**format == 'h') {
    specifier->length = -1;
    (*format)++;
  } else if (**format == 'l') {
    specifier->length = 1;
    (*format)++;
  } else if (**format == 'L') {
    specifier->length = 2;
    (*format)++;
  }
  specifier->type = **format;
  return specifier;
}

void WidthCheck(specifier_s *specifier, const char **format) {
  while (IsDigit(**format)) {
    specifier->width = specifier->width * 10 + (**format - 48);
    (*format)++;
  }
}

specifier_s *InitSpecifier() {
  specifier_s *tmp = calloc(1, sizeof(specifier_s));
  tmp->flag = '0';
  tmp->astrix = 0;
  tmp->width = INF;
  tmp->width--;
  tmp->accuracy = 0;
  tmp->length = 0;
  tmp->type = '0';
  return tmp;
}

void AssignC(const char **str, va_list args, specifier_s *specifier) {
  if (!specifier->astrix) {
    *va_arg(args, char *) = **str;
  }
  (*str)++;
}

void AssignD(const char **str, va_list args, specifier_s *specifier) {
  int sign = 1;
  if (**str == '-') {
    specifier->width--;
    (*str)++;
    sign = -1;
  }
  char tmp = **str;
  long int number = StringToInt(str, specifier);
  number *= sign;
  if (IsDigit(tmp) && !specifier->astrix) AssignInt(number, args, specifier);
}

void AssignI(const char **str, va_list args, specifier_s *specifier) {
  long int number = 0;
  int sign = 1;
  char tmp = '1';
  if (**str == '-') {
    specifier->width--;
    (*str)++;
    sign = -1;
  }
  if (**str == '0') {
    specifier->width--;
    (*str)++;
    if (**str == 'x' || **str == 'X') {
      specifier->width--;
      (*str)++;
      if (IsHex(**str)) {
        number = HexToInt(str, specifier);
      }
    } else {
      if (**str >= '0' && **str <= '7') {
        number = OctToInt(str, specifier);
      }
    }
  } else {
    tmp = **str;
    number = StringToInt(str, specifier);
  }
  number *= sign;
  if (IsDigit(tmp) && !specifier->astrix) AssignInt(number, args, specifier);
}

void AssignX(const char **str, va_list args, specifier_s *specifier) {
  unsigned int number = 0;
  int sign = 1;
  if (**str == '-') {
    specifier->width--;
    (*str)++;
    sign = -1;
  }
  if (**str == '0') {
    specifier->width--;
    (*str)++;
  }
  if (**str == 'x' || **str == 'X') {
    specifier->width--;
    (*str)++;
  }
  char tmp = **str;
  number = HexToInt(str, specifier);
  if (!specifier->astrix) {
    number *= sign;
    if (IsHex(tmp)) *va_arg(args, unsigned int *) = number;
  }
}

void AssignP(const char **str, va_list args, specifier_s *specifier) {
  long int number = 0;
  if (**str == '0') {
    specifier->width--;
    (*str)++;
  }
  if (**str == 'x' || **str == 'X') {
    specifier->width--;
    (*str)++;
  }
  char tmp = **str;
  number = HexToInt(str, specifier);
  if (!specifier->astrix) {
    if (IsHex(tmp)) *va_arg(args, void **) = (void **)number;
  }
}

void AssignO(const char **str, va_list args, specifier_s *specifier) {
  unsigned int number = 0;
  int sign = 1;
  if (**str == '-') {
    specifier->width--;
    (*str)++;
    sign = -1;
  }
  char tmp = **str;
  number = OctToInt(str, specifier);
  if (!specifier->astrix) {
    number *= sign;
    if (tmp >= '0' && tmp <= '7') *va_arg(args, unsigned int *) = number;
  }
}

void AssignS(const char **str, va_list args, specifier_s *specifier) {
  int str_len = 2;
  char *line = calloc(str_len, sizeof(char));
  int i = 0;
  (*str)--;
  for (; *(++(*str)) != 0 && !IsBlanc(**str) && specifier->width-- > 0; i++) {
    if (i >= str_len - 1) {
      str_len *= 2;
      line = realloc(line, str_len * sizeof(char));
      for (int j = i; j < str_len; j++) {
        line[j] = 0;
      }
    }
    line[i] = **str;
  }
  str_len = s21_strlen(line);
  if (!specifier->astrix) {
    s21_strncpy(&(*va_arg(args, char *)), line, str_len + 1);
  }
  free(line);
}

void AssignF(const char **str, va_list args, specifier_s *specifier) {
  long double sign = 1.0;
  if (**str == '-') {
    specifier->width--;
    (*str)++;
    sign = -1.0;
  }
  long double number = StringToFloat(str, specifier);
  number *= sign;
  if (!specifier->astrix) AssignFloat(number, args, specifier);
}

void AssignU(const char **str, va_list args, specifier_s *specifier) {
  long unsigned int number = StringToInt(str, specifier);
  if (!specifier->astrix) AssignUnsigned(number, args, specifier);
}

void AssignInt(long int number, va_list args, specifier_s *specifier) {
  if (specifier->length == -1) {
    *va_arg(args, short int *) = number;
  } else if (specifier->length == 1) {
    *va_arg(args, long int *) = number;
  } else {
    *va_arg(args, int *) = number;
  }
}

void AssignUnsigned(long int number, va_list args, specifier_s *specifier) {
  if (specifier->length == -1) {
    *va_arg(args, short unsigned int *) = number;
  } else if (specifier->length == 1) {
    *va_arg(args, long unsigned int *) = number;
  } else {
    *va_arg(args, unsigned int *) = number;
  }
}

void AssignFloat(long double number, va_list args, specifier_s *specifier) {
  if (specifier->length == 1) {
    *va_arg(args, double *) = number;
  } else if (specifier->length == 2) {
    *va_arg(args, long double *) = number;
  } else {
    *va_arg(args, float *) = number;
  }
}

long unsigned int HexToInt(const char **str, specifier_s *specifier) {
  long unsigned int number = 0;
  int end = 0;
  while (!end) {
    if (IsHex(**str) && specifier->width-- > 0) {
      number *= 16;
      if (IsDigit(**str)) {
        number += (**str - 48);
      } else if (**str >= 'A' && **str <= 'F') {
        number += (**str - 55);
      } else if (**str >= 'a' && **str <= 'f') {
        number += (**str - 87);
      }
      (*str)++;
    } else {
      end = 1;
    }
  }
  return number;
}

/*long unsigned int NegHexToInt(const char** str, specifier_s* specifier) {
  long unsigned int number = 0;
  int end = 0;
  while (!end) {
    if (IsHex(**str) && specifier->width-- > 0) {
        number *= 16;
        if (IsDigit(**str)) {
          number += (63 - **str);
        } else if (**str >= 'A' && **str <= 'F') {
          number += (70 - **str);
        } else if (**str >= 'a' && **str <= 'f') {
          number += (102 - **str);
        }
      (*str)++;
    }else {
      end = 1;
    }
  }
  return -number - 1;
}*/

long unsigned int OctToInt(const char **str, specifier_s *specifier) {
  long unsigned int number = 0;
  int end = 0;
  while (!end) {
    if (**str >= '0' && **str <= '7' && specifier->width-- > 0) {
      number *= 8;
      number += (**str - 48);
      (*str)++;
    } else {
      end = 1;
    }
  }
  return number;
}

/*long unsigned int NegOctToInt(const char** str, specifier_s* specifier) {
  long unsigned int number = 0;
  int end = 0;
  while (!end) {
    if (**str >= '0' && **str <= '7' && specifier->width-- > 0) {
        number *= 8;
        number += (56 - **str);
      (*str)++;
    } else {
      end = 1;
    }
  }
  return -number - 1;
}*/

long unsigned int StringToInt(const char **str, specifier_s *specifier) {
  long unsigned int number = 0;
  while (IsDigit(**str) && **str != '\0' && specifier->width-- > 0) {
    number *= 10;
    number += (**str - 48);
    (*str)++;
  }
  return number;
}

long double StringToFloat(const char **str, specifier_s *specifier) {
  long double number = 0.0;
  int exp = 0;
  number = ReadMantisa(number, str, &exp, specifier);
  if (**str == 'e' || **str == 'E') {
    specifier->width--;
    exp = AdjustExp(str, exp, specifier);
  }
  number = ApplyExp(number, exp);
  return number;
}

long double ReadMantisa(long double number, const char **str, int *exp,
                        specifier_s *specifier) {
  while (IsDigit(**str) && **str != '\0' && specifier->width-- > 0) {
    number *= 10.0;
    number += (**str - 48);
    (*str)++;
  }
  if (**str == '.') {
    specifier->width--;
    (*str)++;
    while (IsDigit(**str) && **str != '\0' && specifier->width-- > 0) {
      number *= 10.0;
      number += (**str - 48);
      *exp = *exp - 1;
      (*str)++;
    }
  }
  return number;
}

int IsDigit(const char str) {
  int is_digit = 0;
  if (str >= '0' && str <= '9') is_digit = 1;
  return is_digit;
}

int IsHex(const char str) {
  int is_hex = 0;
  if ((str >= '0' && str <= '9') || (str >= 'A' && str <= 'F') ||
      (str >= 'a' && str <= 'f'))
    is_hex = 1;
  return is_hex;
}

int IsBlanc(const char str) {
  int is_blanc = 0;
  if (str == 32 || str == 9 || str == 10) is_blanc = 1;
  return is_blanc;
}

int AdjustExp(const char **str, int exp, specifier_s *specifier) {
  int exp_sign = 1;
  int i = 0;
  (*str)++;
  specifier->width--;
  if (**str == '+')
    (*str)++;
  else if (**str == '-') {
    (*str)++;
    exp_sign = -1;
  }
  while (IsDigit(**str) && **str != '\0' && specifier->width-- > 0) {
    i = i * 10 + (**str - 48);
    (*str)++;
  }
  exp += i * exp_sign;
  return exp;
}

long double ApplyExp(long double number, int exp) {
  while (exp > 0) {
    number *= 10.0;
    exp--;
  }
  while (exp < 0) {
    number *= 0.1;
    exp++;
  }
  return number;
}