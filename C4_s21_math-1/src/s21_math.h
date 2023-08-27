#ifndef S21_MATH
#define S21_MATH

#define S21_PI 3.1415926535897932384626433832795028841971
#define S21_PI_2 1.5707963267948966192313216
#define S21_EXP 2.7182818284590452353602874713527
#define S21_EPS 1e-7
#define _HUGE_ENUF 1e+300
#define BIGGEST_LF 9007199254740992
#define INF ((float)(_HUGE_ENUF * _HUGE_ENUF))
#define NaN (double)(INF * 0.0F)
#define EPS_TEYLOR 1e-18
#define MAX_SIZE_TEYLOR 4000
#define MAX_SIZE 800

#define ISNAN(x) (x != x)
#define ISINF(x) ((x == INF) || (x == -INF))

int s21_abs(int x);
long double s21_ceil(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_exp(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_log(double x);
long double s21_sqrt(double x);
long double PowInt(double base, long long exp);
long double PowDouble(double base, double exp);
long double s21_pow(double base, double exp);

#endif
