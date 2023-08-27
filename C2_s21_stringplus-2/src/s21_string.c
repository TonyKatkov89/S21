#include "s21_string.h"

#include "s21_errno.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  char *ptr = (char *)str;
  char cr = c;
  void *res = s21_NULL;
  for (s21_size_t i = 0; i < n; i++) {
    if (*(ptr + i) == cr) {
      res = ptr + i;
      break;
    }
  }
  return res;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *d = (char *)dest;
  const char *s = (char *)src;
  while (n--) {
    *(d++) = *(s++);
  }
  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *tmp = dest;
  while (*tmp) {
    tmp++;
  }
  while (n-- && *src) {
    *(tmp++) = *(src++);
  }
  *tmp = 0;
  return dest;
}

s21_size_t s21_strlen(const char *str) {
  size_t length = 0;
  while (*(str++)) {
    ++length;
  }
  return length;
}

char *s21_strchr(const char *str, int c) {
  char *ptr = s21_NULL;
  int len = s21_strlen(str);
  for (int i = 0; i < len + 1; i++) {
    if (str[i] == c) {
      ptr = (char *)(str + i);
      break;
    }
  }
  return ptr;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *tmp = dest;
  for (s21_size_t i = 0; i < n; i++) {
    tmp[i] = *src;
    if (*src) {
      src++;
    }
  }
  return dest;
}

char *s21_strerror(int errnum) {
  char *errors[] = ERR_MSGS;
  char *ptr;
  if (errnum >= 0 && errnum <= 133) {
    ptr = errors[errnum];
  } else {
    static char tmp[50];
    s21_sprintf(tmp, "%s %d", UE_MSG, errnum);
    ptr = tmp;
  }
  return ptr;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *ptr = s21_NULL;
  while (*str1 && ptr == s21_NULL) {
    for (int i = 0; str2[i] && ptr == s21_NULL; i++) {
      if (*str1 == str2[i]) {
        ptr = (char *)str1;
        break;
      }
    }
    str1++;
  }
  return ptr;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *ptr = s21_NULL;
  while (*haystack && ptr == s21_NULL) {
    ptr = (char *)haystack;
    for (int i = 0; needle[i]; i++) {
      if (needle[i] != ptr[i]) {
        ptr = s21_NULL;
        break;
      }
    }
    haystack++;
  }
  return ptr;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *copy1 = str1;
  const unsigned char *copy2 = str2;
  int res = 0;
  if (str1 == str2) {
    return res;
  }
  while (n > 0) {
    if (*copy1 != *copy2) {
      if (*copy1 > *copy2) {
        res = 1;
      } else {
        res = -1;
      }
      break;
    }
    n--;
    copy1++;
    copy2++;
  }
  return res;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) *((char *)str + i) = c;
  return str;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  if (n != 0) {
    while (n-- != 0)
      if (*str1++ != *str2++) {
        result = *--str1 - *--str2;
        break;
      }
  }
  return result;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  while (*str1) {
    if (s21_strchr(str2, *str1) != s21_NULL) {
      break;
    } else {
      str1++;
      res++;
    }
  }
  return res;
}

char *s21_strrchr(const char *str, int c) {
  char *res = s21_NULL;
  while (*str) {
    if (*str == (char)c) {
      res = (char *)str;
    }
    ++str;
  }
  if (*str == (char)c) {
    res = (char *)str;
  }
  return res;
}

int is_separator(char c, const char *separator) {
  int res = 0;

  while (res == 0 && (*separator != '\0')) {
    if (c == *separator) {
      res = 1;
    }
    separator++;
  }
  return res;
}

char *s21_strtok(char *str, const char *delim) {
  static char *tmp;
  char *res;
  if (!str) {
    str = tmp;
  }
  while ((*str != '\0') && is_separator(*str, delim)) {
    str++;
  }
  if (*str != '\0') {
    res = str;
    while (*str != '\0' && !is_separator(*str, delim)) {
      if (*(str + 1) == '\0') {
        tmp = str + 1;
      }
      if (is_separator(*(str + 1), delim)) {
        *(str + 1) = '\0';
        tmp = str + 2;
      }
      str++;
    }
  } else {
    res = s21_NULL;
  }
  return res;
}

char *s21_strcat(char *dest, const char *s) {
  char *tmp = dest + s21_strlen(dest);
  while (*s != '\0') {
    *tmp++ = *s++;
  }
  *tmp = '\0';
  return dest;
}

int IsLower(const char c) { return (c >= 'a' && c <= 'z') ? 1 : 0; }

int IsUpper(const char c) { return (c >= 'A' && c <= 'Z') ? 1 : 0; }

void *s21_to_upper(char *str) {
  char *new_str = calloc(s21_strlen(str) + 1, sizeof(char));
  char *tmp = new_str;
  while (*str) {
    if (IsLower(*str)) {
      *tmp = *str - 32;
    } else {
      *tmp = *str;
    }
    str++;
    tmp++;
  }
  return new_str;
}

void *s21_to_lower(char *str) {
  char *new_str = calloc(s21_strlen(str) + 1, sizeof(char));
  char *tmp = new_str;
  while (*str) {
    if (IsUpper(*str)) {
      *tmp = *str + 32;
    } else {
      *tmp = *str;
    }
    str++;
    tmp++;
  }
  return new_str;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_str = s21_NULL;
  s21_size_t src_l = src ? s21_strlen(src) : 0;
  s21_size_t str_l = str ? s21_strlen(str) : 0;
  s21_size_t full_l = src_l + str_l;
  if (start_index <= src_l && src && str) {
    new_str = calloc(full_l + 2, sizeof(char));
    s21_size_t i = 0;
    int j = 0;
    int l = 0;
    for (; i < full_l;) {
      if (i == start_index && *(str + j) != '\0') {
        while (*(str + j) != '\0') {
          new_str[i++] = str[j++];
        }
      } else {
        new_str[i++] = src[l++];
      }
    }
  }
  return new_str;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *new_str = s21_NULL;
  s21_size_t length = src ? s21_strlen(src) : 0;

  if (src) {
    new_str = calloc((length + 1), sizeof(char));
    if (new_str && trim_chars) {
      s21_size_t i = 0, j = 0;
      for (; i < length; i++) {
        if (s21_strchr(trim_chars, src[i]) == s21_NULL) {
          break;
        }
      }
      for (; i < length;) {
        new_str[j++] = src[i++];
      }

      for (; j != 0 && s21_strchr(trim_chars, new_str[--j]) && j < length;) {
        new_str[j] = '\0';
      }
    }
  }

  return new_str;
}