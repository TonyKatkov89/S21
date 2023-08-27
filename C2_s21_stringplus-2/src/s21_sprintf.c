#include "math.h"
#include "s21_string.h"
#include "stdarg.h"
#include "stdlib.h"

#define OK 0;
#define ERR 1;

struct specif {
  int c;
  int d;
  int i;
  int f;
  int s;
  int o;
  int x;
  int X;
  int u;
  int p;
  int n;
  int e;
  int E;
  int g;
  int G;
};

struct flag {
  int minus;
  int plus;
  int space;
  int hash;
  int zero;
};

struct length {
  int l;
  int L;
  int h;
};

struct sprintf_format {
  struct specif specif;
  struct flag flag;
  int precision;
  int width;
  struct length length;
};

int parsing(struct sprintf_format *F, char **format) {
  if (**format == 'f') {
    F->specif.f = 1;
  } else if (**format == 'c') {
    F->specif.c = 1;
  } else if (**format == 'd') {
    F->specif.d = 1;
  } else if (**format == 'i') {
    F->specif.i = 1;
  } else if (**format == 's') {
    F->specif.s = 1;
  } else if (**format == 'o') {
    F->specif.o = 1;
  } else if (**format == 'x') {
    F->specif.x = 1;
  } else if (**format == 'X') {
    F->specif.X = 1;
  } else if (**format == 'u') {
    F->specif.u = 1;
  } else if (**format == 'p') {
    F->specif.p = 1;
  } else if (**format == 'n') {
    F->specif.n = 1;
  } else if (**format == 'e') {
    F->specif.e = 1;
  } else if (**format == 'E') {
    F->specif.E = 1;
  } else if (**format == 'g') {
    F->specif.g = 1;
  } else if (**format == 'G') {
    F->specif.G = 1;
  }
  return 0;
}

void reset(struct sprintf_format *F) {
  F->specif.c = 0;
  F->specif.d = 0;
  F->specif.i = 0;
  F->specif.f = 0;
  F->specif.s = 0;
  F->specif.o = 0;
  F->specif.x = 0;
  F->specif.X = 0;
  F->specif.u = 0;
  F->specif.p = 0;
  F->specif.n = 0;
  F->specif.e = 0;
  F->specif.E = 0;
  F->specif.g = 0;
  F->specif.G = 0;
  F->flag.minus = 0;
  F->flag.plus = 0;
  F->flag.hash = 0;
  F->flag.space = 0;
  F->flag.zero = 0;
  F->precision = -1;
  F->width = 0;
  F->length.l = 0;
  F->length.L = 0;
  F->length.h = 0;
}

void reverse(char str[], int length) {
  int start = 0;
  int end = length - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    end--;
    start++;
  }
}

char *my_itoa(int n, char *str) {
  int i = 0;
  int tmp = n;
  if (n == 0) {
    str[i++] = '0';
    str[i] = '\0';
    return str;
  }
  if (n < 0) tmp *= -1;
  while (tmp != 0) {
    str[i++] = tmp % 10 + '0';
    tmp = tmp / 10;
  }
  if (n < 0) {
    str[i] = '-';
    i++;
  }
  str[i] = '\0';
  reverse(str, i);
  return str;
}

int my_atoi(char *str) {
  int res;
  for (int i = 0; str[i] != '\0'; ++i) res = res * 10 + str[i] - '0';

  return res;
}

void apply_width(char **str, int tmp_len, struct sprintf_format *F) {
  int width = F->width;
  int precision = F->precision;
  while (width > precision && width-- > tmp_len) {
    if (F->flag.zero == 1 && F->flag.minus == 0) {
      **str = '0';
    } else {
      **str = ' ';
    }
    *str = *str + 1;
  }
}

void apply_precison(char **str, int tmp_len, struct sprintf_format *F) {
  // int width = F->width;
  int precision = F->precision;
  while (precision-- > tmp_len) {
    **str = '0';
    *str = *str + 1;
  }
}

char *d_specif(char *str, int arg, struct sprintf_format *F) {
  char *tmp_arr = calloc(1000, sizeof(char));
  char *tmp2 = calloc(1000, sizeof(char));
  char *tmp = tmp_arr;
  if (F->length.h) {
    arg = (short)arg;
  }
  if (F->flag.plus) {
    s21_strcat(tmp, "+");
  }
  if (F->flag.space) {
    s21_strcat(tmp, " ");
  }
  my_itoa(arg, tmp2);
  s21_strcat(tmp, tmp2);
  free(tmp2);
  if (arg == 0 && F->precision == 0) *tmp = '\0';
  int tmp_len = s21_strlen(tmp);
  if (F->flag.minus == 0) apply_width(&str, tmp_len, F);
  apply_precison(&str, tmp_len, F);
  while (*tmp) {
    *str++ = *tmp++;
  }
  if (F->flag.minus == 1) apply_width(&str, tmp_len, F);
  *str = '\0';
  free(tmp_arr);
  return str;
}
void my_longtoa(char *str, long int arg) {
  int i = 0;
  if (arg < 0) {
    arg = arg * -1;
  }
  while (arg > 0) {
    str[i++] = arg % 10 + '0';
    arg /= 10;
  }
  if (arg < 0) {
    str[i++] = '-';
  }
  str[i] = '\0';
  reverse(str, s21_strlen(str));
}
char *long_d_specif(char *str, long int arg, struct sprintf_format *F) {
  char *tmp = calloc(1024, sizeof(char));
  char *ptr = tmp;
  if (F->flag.plus) {
    tmp[0] = '+';
    ptr++;
  }
  my_longtoa(ptr, arg);
  if (arg == 0 && F->precision == 0) *ptr = '\0';
  int tmp_len = s21_strlen(ptr);
  if (F->flag.minus == 0) apply_width(&str, tmp_len, F);
  apply_precison(&str, tmp_len, F);
  while (*ptr) *str++ = *ptr++;
  *str = '\0';
  free(tmp);
  return str;
}

int is_digit(char c) { return (c >= '0') && (c <= '9'); }

char *f_specif(char *str, double arg, struct sprintf_format *F) {
  if (F->precision == -1) {
    F->precision = 6;
  }
  char *arr = calloc(1000, sizeof(char));
  char *tmp = arr;
  my_itoa((int)arg, tmp);
  if (F->flag.hash || F->precision) {
    s21_strcat(tmp, ".");
  }
  if (F->precision && !F->flag.hash) {
    double decimal = arg - (int)arg;
    int precision = F->precision;
    while (precision--) decimal *= 10;
    char *arr2 = calloc(1000, sizeof(char));
    char *tmp_2 = arr2;
    my_itoa(abs((int)round(decimal)), tmp_2);
    int len = s21_strlen(tmp_2);
    while (len++ < F->precision) s21_strcat(tmp, "0");
    s21_strcat(tmp, tmp_2);
    free(arr2);
  } else if (F->flag.hash) {
    s21_strcat(tmp, "000000");
  }
  int tmp_len = s21_strlen(tmp);
  if (F->flag.minus == 0) apply_width(&str, tmp_len, F);
  while (*tmp) *str++ = *tmp++;
  if (F->flag.minus == 1) apply_width(&str, tmp_len, F);
  *str = '\0';
  s21_strcat(str, tmp);
  free(arr);

  return str;
}

char *s_specif(char *str, char *s, struct sprintf_format *F) {
  char *arr = calloc(1000, sizeof(char));
  char *tmp = arr;
  int counter = 0;
  while (*s != '\0') {
    tmp[counter++] = *s++;
  }
  char *tmp_2 = tmp;
  int tmp_len = s21_strlen(tmp);
  if (F->precision != -1 && F->precision < tmp_len) {
    tmp_len = F->precision;
  } else {
    F->precision = -1;
  }
  if (F->flag.minus == 0) apply_width(&str, tmp_len, F);
  for (int i = 0; i < tmp_len && *tmp_2 != '\0'; i++) {
    *str++ = *tmp_2++;
  }
  if (F->flag.minus == 1) apply_width(&str, tmp_len, F);
  *str = '\0';
  free(arr);
  return str;
}

char *long_s_specif(char *str, wchar_t *s, struct sprintf_format *F) {
  char tmp1[1024] = {};
  char tmp2[1024] = {};
  char *ptr = tmp2;
  for (int i = 0; s[i] != '\0'; i++) {
    tmp1[i] = (char)s[i];
  }

  int tmp_len = s21_strlen(tmp1);
  if (F->flag.minus == 0) apply_width(&str, tmp_len, F);
  for (int j = 0; tmp_len > 0; j++, tmp_len--) {
    ptr[j] = tmp1[j];
  }

  if (F->flag.minus == 1) apply_width(&str, tmp_len, F);
  while (*ptr) *str++ = *ptr++;
  *str = '\0';
  return str;
}

char *c_specif(char *str, int arg, struct sprintf_format *F) {
  char *arr = calloc(1000, sizeof(char));
  char *tmp = arr;
  *tmp = (char)arg;
  int tmp_len = s21_strlen(tmp);
  if (F->flag.minus == 0) apply_width(&str, tmp_len, F);
  *str++ = *tmp++;
  while (*tmp != '\0') {
    *str++ = *tmp++;
  }
  if (F->flag.minus == 1) apply_width(&str, tmp_len, F);
  *str = '\0';
  free(arr);
  return str;
}

void change_notation(unsigned long int arg, int notation,
                     struct sprintf_format *F, char *str) {
  const char octal[] = "01234567";
  const char hexadecimal[] = "0123456789abcdef";
  const char big_hexadecimal[] = "0123456789ABCDEF";

  int i = 0;
  char arr[1000] = {};
  char *tmp = arr;
  if (F->specif.o) {
    while (arg != 0 && notation != 0) {
      int x = arg % notation;
      tmp[i] = octal[x];
      arg /= notation;
      i++;
    }
  } else if (F->specif.x) {
    while (arg != 0 && notation != 0) {
      int x = arg % notation;
      tmp[i] = hexadecimal[x];
      arg /= notation;
      i++;
    }
  } else if (F->specif.X) {
    while (arg != 0 && notation != 0) {
      int x = arg % notation;
      tmp[i] = big_hexadecimal[x];
      arg /= notation;
      i++;
    }
  }
  tmp[i] = '\0';
  reverse(tmp, s21_strlen(tmp));
  s21_strcat(str, tmp);
}

char *o_specif(char *str, int arg, struct sprintf_format *F) {
  char *arr = calloc(1000, sizeof(char));
  char *tmp = arr;
  if (F->flag.hash) {
    s21_strcat(tmp, "0");
  }
  if (arg == 0) {
    int i = 0;
    tmp[i++] = arg + '0';
  } else {
    change_notation(arg, 8, F, tmp);
  }
  if (arg == 0) *tmp = '\0';
  int tmp_len = s21_strlen(tmp);
  if (F->flag.minus == 0) apply_width(&str, tmp_len, F);
  apply_precison(&str, tmp_len, F);
  while (*tmp) *str++ = *tmp++;
  if (F->flag.minus == 1) apply_width(&str, tmp_len, F);
  *str = '\0';
  free(arr);
  return str;
}

char *long_o_specif(char *str, long int arg, struct sprintf_format *F) {
  char *arr = calloc(1000, sizeof(char));
  char *tmp = arr;
  if (arg == 0) {
    int i = 0;
    tmp[i++] = arg + '0';
  } else {
    change_notation(arg, 8, F, tmp);
  }
  if (arg == 0) *tmp = '\0';
  int tmp_len = s21_strlen(tmp);
  if (F->flag.minus == 0) apply_width(&str, tmp_len, F);
  apply_precison(&str, tmp_len, F);
  while (*tmp) *str++ = *tmp++;
  if (F->flag.minus == 1) apply_width(&str, tmp_len, F);
  *str = '\0';
  free(arr);
  return str;
}

void my_utoa(s21_size_t n, char *str) {
  int i = 0;
  if (n == 0) {
    str[i] = n + '0';
    i++;
  } else {
    while (n > 0) {
      str[i] = n % 10 + '0';
      i++;
      n /= 10;
    }
  }
  str[i] = '\0';
  reverse(str, s21_strlen(str));
}

char *u_specif(char *str, s21_size_t arg, struct sprintf_format *F) {
  char *arr = calloc(1000, sizeof(char));
  char *tmp = arr;
  my_utoa(arg, tmp);
  if (arg == 0 && F->precision == 0) *tmp = '\0';
  int tmp_len = s21_strlen(tmp);
  if (F->flag.minus == 0) apply_width(&str, tmp_len, F);
  apply_precison(&str, tmp_len, F);
  while (*tmp) *str++ = *tmp++;
  if (F->flag.minus == 1) apply_width(&str, tmp_len, F);
  *str = '\0';
  free(arr);
  return str;
}

char *long_u_specif(char *str, s21_size_t arg, struct sprintf_format *F) {
  char *arr = calloc(1000, sizeof(char));
  char *tmp = arr;
  int i = 0;
  while (arg > 0) {
    tmp[i] = arg % 10 + '0';
    i++;
    arg /= 10;
  }
  tmp[i] = '\0';
  reverse(tmp, s21_strlen(tmp));

  if (arg == 0 && F->precision == 0) *tmp = '\0';
  int tmp_len = s21_strlen(tmp);
  if (F->flag.minus == 0) apply_width(&str, tmp_len, F);
  apply_precison(&str, tmp_len, F);
  while (*tmp) *str++ = *tmp++;
  if (F->flag.minus == 1) apply_width(&str, tmp_len, F);
  *str = '\0';
  free(arr);
  return str;
}

char *x_specif(char *str, long int arg, struct sprintf_format *F) {
  char *arr = calloc(1000, sizeof(char));
  char *tmp = arr;
  if (F->flag.hash && F->specif.x) {
    s21_strcat(tmp, "0x");
  } else if (F->flag.hash && F->specif.X) {
    s21_strcat(tmp, "0X");
  }
  if (arg == 0) {
    int i = 0;
    tmp[i++] = arg + '0';
  } else {
    change_notation(arg, 16, F, tmp);
  }
  if (arg == 0) *tmp = '\0';
  int tmp_len = s21_strlen(tmp);
  if (F->flag.minus == 0) apply_width(&str, tmp_len, F);
  apply_precison(&str, tmp_len, F);
  while (*tmp) *str++ = *tmp++;
  if (F->flag.minus == 1) apply_width(&str, tmp_len, F);
  *str = '\0';
  free(arr);
  return str;
}

char *p_convert(long x, int hex) {
  long num = x;
  const char arr[] = "0123456789abcdef";
  static char buffer[1024];
  char *ptr = buffer;
  while (num != 0 && hex != 0) {
    *--ptr = arr[num % hex];
    num /= hex;
  }
  return (ptr);
}

char *p_specif(char *str, void *arg, struct sprintf_format *F) {
  static char tmp[1024] = "0x";
  char *ptr = tmp;
  long int address = (long int)arg;

  const char hexadecimal[] = "0123456789abcdef";
  static char tmp_2[1024];
  char *ptr_2 = tmp_2;
  while (address != 0) {
    *--ptr_2 = hexadecimal[address % 16];
    address /= 16;
  }

  s21_strcat(tmp, ptr_2);
  int ptr_len = s21_strlen(ptr);
  if (F->flag.minus == 0) apply_width(&str, ptr_len, F);
  while (*ptr) {
    *str++ = *ptr++;
  }
  if (F->flag.minus == 1) apply_width(&str, ptr_len, F);
  *str = '\0';
  return str;
}

void read_flags(struct sprintf_format *F, char **format) {
  while (s21_strchr("+-0 #", **format)) {
    switch (**format) {
      case '-':
        F->flag.minus = 1;
        break;
      case '+':
        F->flag.plus = 1;
        break;
      case ' ':
        F->flag.space = 1;
        break;
      case '#':
        F->flag.hash = 1;
        break;
      case '0':
        F->flag.zero = 1;
        break;
      default:
        break;
    }
    (*format)++;
  }
}

int read_width(char **format, va_list ap) {
  int width = 0;
  if (**format == '*') {
    width = va_arg(ap, int);
    (*format)++;
  } else if (is_digit(**format)) {
    while (is_digit(**format)) {
      width *= 10;
      width += (**format - 48);
      (*format)++;
    }
  }
  return width;
}

char *my_dtoa(double arg, struct sprintf_format *F, int g_digits) {
  char *res = calloc(1000, sizeof(char));
  char arr1[1000] = {};
  char *part1 = arr1;
  char arr2[1000] = {};
  char *part2 = arr2;

  int integer, decimal, flag = 0;
  double tmp = 0;
  if (arg < 0) {
    arg = arg * (-1);
    flag = 1;
  }
  arg = modf(arg, &tmp);  // Decomposes into int and fract parts, int -> tmp
  integer = tmp;
  my_itoa(integer, res);
  s21_strcat(res, ".");
  if (!(F->specif.g || F->specif.G)) {
    for (int i = 0; i < F->precision; i++) {
      arg = arg * 10;
    }
    arg = round(arg);
    decimal = arg;
    my_itoa(decimal, part1);
  } else {
    for (int i = 0; i < F->precision - g_digits; i++) {
      arg = arg * 10;
    }
    arg = round(arg);

    for (int i = 0; i < F->precision - g_digits; i++) {
      if ((int)arg % 10 != 0) {
        break;
      } else {
        arg = arg / 10;
      }
    }
  }

  decimal = arg;
  my_itoa(decimal, part1);
  s21_strcat(part2, part1);
  s21_strcat(res, part2);

  if (flag == 1) {
    s21_size_t i = s21_strlen(res);
    do {
      res[i + 1] = res[i];
    } while (i--);
    res[0] = '-';
  }

  return res;
}

char *e_specif(char *str, double arg, struct sprintf_format *F) {
  char res[1024] = {};
  char *ptr = res;
  char part1[1024] = {};
  char part2[1024] = {};
  if (F->precision == -1) {
    F->precision = 6;
  }

  int sum = 0;
  int flag = 0;
  if (arg > 0) {
    if (arg < 1) {
      while (arg < 1) {
        arg *= 10;
        sum++;
        flag = 1;
      }
    } else if (arg > 1) {
      while (arg > 9) {
        arg /= 10;
        sum++;
      }
    }
  } else if (arg < 0) {
    if (arg > -1) {
      while (arg > -1) {
        flag = 1;
        arg *= 10;
        sum++;
      }
    } else if (arg < -1) {
      while (arg < -9) {
        arg /= 10;
        sum++;
      }
    }
  }
  char *test = my_dtoa(arg, F, 6);
  s21_strcat(part1, test);
  s21_size_t len1 = s21_strlen(part1);

  if (F->specif.e) {
    part1[len1++] = 'e';
  } else if (F->specif.E) {
    part1[len1++] = 'E';
  }

  if (flag == 1) {
    part1[len1++] = '-';
  } else {
    part1[len1++] = '+';
  }
  my_itoa(sum, part2);

  if (sum < 10) {
    s21_size_t i = s21_strlen(part2);
    do {
      part2[i + 1] = part2[i];
    } while (i--);
    part2[0] = '0';
  }

  s21_strcat(ptr, part1);
  s21_strcat(ptr, part2);
  int ptr_len = s21_strlen(ptr);
  if (F->flag.minus == 0) apply_width(&str, ptr_len, F);
  while (*ptr) {
    *str++ = *ptr++;
  }
  if (F->flag.minus == 1) apply_width(&str, ptr_len, F);
  *str = '\0';
  free(test);
  return str;
}

int count_digits(double arg) {
  if (arg < 0) arg *= -1;
  double tmp = 0;
  int res = 0;
  arg = modf(arg, &tmp);
  while (tmp > 9) {
    tmp = tmp / 10;
    res++;
  }
  res++;
  return res;
}

char *g_specif(char *str, double arg, struct sprintf_format *F) {
  if (arg == 0) {
    *str++ = '0';
    *str = '\0';
    return str;
  }
  char arr[1024] = {};
  char *ptr = arr;
  if (F->precision == -1) {
    F->precision = 6;
  }

  if (count_digits(arg) <= F->precision) {
    char *tmp = my_dtoa(arg, F, count_digits(arg));
    s21_strcat(ptr, tmp);
    free(tmp);
  } else {
    char part1[1024] = {};
    char part2[1024] = {};

    int sum = 0;
    int flag = 0;
    if (arg > 0) {
      if (arg < 1) {
        while (arg < 1) {
          arg *= 10;
          sum++;
          flag = 1;
        }
      } else if (arg > 1) {
        while (arg > 9) {
          arg /= 10;
          sum++;
        }
      }
    } else if (arg < 0) {
      if (arg > -1) {
        while (arg > -1) {
          flag = 1;
          arg *= 10;
          sum++;
        }
      } else if (arg < -1) {
        while (arg < -9) {
          arg /= 10;
          sum++;
        }
      }
    }
    char *tmp2 = my_dtoa(arg, F, count_digits(arg));
    s21_strcat(part1, tmp2);

    s21_size_t len1 = s21_strlen(part1);

    if (F->specif.g) {
      part1[len1++] = 'e';
    } else if (F->specif.G) {
      part1[len1++] = 'E';
    }

    if (flag == 1) {
      part1[len1++] = '-';
    } else {
      part1[len1++] = '+';
    }
    my_itoa(sum, part2);

    if (sum < 10) {
      s21_size_t i = s21_strlen(part2);
      do {
        part2[i + 1] = part2[i];
      } while (i--);
      part2[0] = '0';
    }

    s21_strcat(ptr, part1);
    s21_strcat(ptr, part2);
    free(tmp2);
  }
  int ptr_len = s21_strlen(ptr);
  if (F->precision > ptr_len) {
    F->precision = ptr_len;
  }
  if (F->flag.minus == 0) apply_width(&str, ptr_len, F);
  while (*ptr) {
    *str++ = *ptr++;
  }
  if (F->flag.minus == 1) apply_width(&str, ptr_len, F);
  *str = '\0';
  return str;
}

int read_length(char **arg, struct sprintf_format *F) {
  int res = 0;
  if (**arg == 'l') {
    F->length.l = 1;
    res = 1;
  } else if (**arg == 'L') {
    F->length.L = 1;
    res = 1;
  } else if (**arg == 'h') {
    F->length.h = 1;
    res = 1;
  }
  if (res == 1) {
    (*arg)++;
  }

  return res;
}

int is_spec(char arg) {
  return arg == 'c' || arg == 'd' || arg == 'e' || arg == 'E' || arg == 'i' ||
                 arg == 'f' || arg == 'g' || arg == 'G' || arg == 'o' ||
                 arg == 's' || arg == 'x' || arg == 'X' || arg == 'u' ||
                 arg == 'p' || arg == 'n'
             ? 1
             : 0;
}

int s21_sprintf(char *str, const char *format, ...) {
  struct sprintf_format F;
  va_list ap;
  va_start(ap, format);
  reset(&F);
  char *tmp_format = (char *)format;
  const char *opening = str;
  while (*tmp_format != '\0') {
    if (*tmp_format == '%') {
      tmp_format++;

      read_flags(&F, &tmp_format);
      F.width = read_width(&tmp_format, ap);
      if (*tmp_format == '.') {
        tmp_format++;
        if (is_digit(*tmp_format) || *tmp_format == '*') {
          F.precision = read_width(&tmp_format, ap);
        }
      }
      read_length(&tmp_format, &F);

      parsing(&F, &tmp_format);
      if (is_spec(*tmp_format)) {
        tmp_format++;
      }
      if (*tmp_format == '%') {
        *str++ = *tmp_format++;
      }

      // specif
      if (F.specif.d || F.specif.i) {
        if (F.length.l) {
          str = long_d_specif(str, va_arg(ap, long int), &F);
        } else {
          str = d_specif(str, va_arg(ap, int), &F);
        }
      } else if (F.specif.c) {
        if (F.length.l) {
          str = c_specif(str, (int)va_arg(ap, wchar_t), &F);
        } else {
          str = c_specif(str, va_arg(ap, int), &F);
        }
      } else if (F.specif.f) {
        if (F.length.L) {
          str = f_specif(str, va_arg(ap, long double), &F);
        } else {
          str = f_specif(str, va_arg(ap, double), &F);
        }
      } else if (F.specif.s) {
        if (F.length.l) {
          str = long_s_specif(str, va_arg(ap, wchar_t *), &F);
        } else {
          str = s_specif(str, va_arg(ap, char *), &F);
        }
      } else if (F.specif.o) {
        if (F.length.l) {
          str = long_o_specif(str, va_arg(ap, long int), &F);
        } else {
          str = o_specif(str, va_arg(ap, int), &F);
        }
      } else if (F.specif.u) {
        if (F.length.l) {
          str = long_u_specif(str, va_arg(ap, s21_size_t), &F);
        } else {
          str = u_specif(str, va_arg(ap, s21_size_t), &F);
        }
      } else if (F.specif.x || F.specif.X) {
        str = x_specif(str, va_arg(ap, long int), &F);
      } else if (F.specif.p) {
        str = p_specif(str, va_arg(ap, void *), &F);
      } else if (F.specif.n) {
        *va_arg(ap, int *) = str - opening;
      } else if (F.specif.e || F.specif.E) {
        if (F.length.L) {
          str = e_specif(str, va_arg(ap, long double), &F);
        } else {
          str = e_specif(str, va_arg(ap, double), &F);
        }
      } else if (F.specif.g || F.specif.G) {
        if (F.length.L) {
          str = g_specif(str, va_arg(ap, long double), &F);
        } else {
          str = g_specif(str, va_arg(ap, double), &F);
        }
      }
      reset(&F);
    } else {
      *str++ = *tmp_format++;
    }
  }
  va_end(ap);
  return str - opening;
}