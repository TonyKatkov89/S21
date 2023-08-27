#ifndef S21_STRING_H_
#define S21_STRING_H_

#include <stdarg.h>
#include <stdlib.h>

#define s21_NULL (void *)0
#define _HUGE_ENUF 1e+300
#define INF ((float)(_HUGE_ENUF * _HUGE_ENUF))

typedef struct specifier {
  int specifiers_qtty;
  char flag;
  int astrix;
  int width;
  int accuracy;
  int length;
  char type;
} specifier_s;

typedef unsigned long s21_size_t;
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strtok(char *str, const char *delim);
void *s21_memchr(const void *str, int c, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strlen(const char *str);
char *s21_strchr(const char *str, int c);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strerror(int errnum);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok_r(char *str, const char *delim, char **save_ptr);
char *s21_strcat(char *dest, const char *s);
void *s21_to_upper(char *str);
void *s21_to_lower(char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
int s21_sprintf(char *str, const char *format, ...);
int s21_sscanf(const char *str, const char *format, ...);
int Parce(const char *str, const char *format, va_list args);
int AssignValues(const char *beginning, const char **str, va_list args,
                 specifier_s *specifier);
specifier_s *ParceSpecifier(const char **format);
void WidthCheck(specifier_s *specifier, const char **format);
specifier_s *InitSpecifier();
void AssignC(const char **str, va_list args, specifier_s *specifier);
void AssignD(const char **str, va_list args, specifier_s *specifier);
void AssignI(const char **str, va_list args, specifier_s *specifier);
void AssignX(const char **str, va_list args, specifier_s *specifier);
void AssignP(const char **str, va_list args, specifier_s *specifier);
void AssignO(const char **str, va_list args, specifier_s *specifier);
void AssignS(const char **str, va_list args, specifier_s *specifier);
void AssignF(const char **str, va_list args, specifier_s *specifier);
void AssignU(const char **str, va_list args, specifier_s *specifier);
void AssignInt(long int number, va_list args, specifier_s *specifier);
void AssignUnsigned(long int number, va_list args, specifier_s *specifier);
void AssignFloat(long double number, va_list args, specifier_s *specifier);
long unsigned int HexToInt(const char **str, specifier_s *specifier);
long unsigned int NegHexToInt(const char **str, specifier_s *specifier);
long unsigned int OctToInt(const char **str, specifier_s *specifier);
long unsigned int NegOctToInt(const char **str, specifier_s *specifier);
long unsigned int StringToInt(const char **str, specifier_s *specifier);
long double StringToFloat(const char **str, specifier_s *specifier);
long double ReadMantisa(long double number, const char **str, int *exp,
                        specifier_s *specifier);
int AdjustExp(const char **str, int exp, specifier_s *specifier);
long double ApplyExp(long double number, int exp);
int IsDigit(const char str);
int IsHex(const char str);
int IsBlanc(const char str);

#endif
