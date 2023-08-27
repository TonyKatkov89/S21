#include "s21_math.h"

#include <stdio.h>

int s21_abs(int x) { return x < 0 ? -x : x; }

long double s21_ceil(double x) {
  long double result = (long long)x;
  if (ISNAN(x) || ISINF(x)) {
    result = x;
  } else if (x != result && x > 0) {
    ++result;
  }
  return result;
}

long double s21_fabs(double x) { return x >= 0 || ISNAN(x) ? x : -x; }

long double s21_floor(double x) {
  long double result = (long long)x;
  if (ISNAN(x) || ISINF(x)) {
    result = x;
  } else if (x != result && x < 0) {
    --result;
  }
  return result;
}

long double s21_fmod(double x, double y) {
  long double result;
  if (ISNAN(x) || ISNAN(y)) {
    result = -NaN;
  } else if (y == 0.0 || ISINF(x)) {
    result = NaN;
  } else if (ISINF(y) || x == 0.0) {
    result = x;
  } else {
    if ((x < 0 && y >= 0) || (x >= 0 && y < 0)) {
      result = x - s21_ceil(x / y) * y;
    } else {
      result = x - s21_floor(x / y) * y;
    }
  }
  return result;
}

long double s21_sin(double x) {
  long double result = 0, prev_result = 1, fact = 1, pow_x;
  int temp_x = 1, count = 1;
  x = s21_fmod(x, 2 * S21_PI);
  pow_x = x;
  do {
    prev_result = result;
    result += (temp_x * pow_x) / fact;
    fact *= (2 * count) * (1 + 2 * count);
    pow_x *= x * x;
    temp_x *= -1;
    count++;
  } while (s21_fabs(result - prev_result) > S21_EPS && count < 500);
  return result;
}

long double s21_cos(double x) {
  long double result = 0, prev_result = 1, fact = 1, pow_x = 1;
  int temp_x = 1, count = 2;
  x = s21_fmod(x, 2 * S21_PI);
  do {
    prev_result = result;
    result += (temp_x * pow_x) / fact;
    fact *= (count - 1) * count;
    pow_x *= x * x;
    temp_x *= -1;
    count += 2;
  } while (s21_fabs(result - prev_result) > S21_EPS && count < 1000);
  return result;
}

long double s21_tan(double x) {
  long double result;
  if (x > -S21_PI_2 - EPS_TEYLOR && x < -S21_PI_2 + EPS_TEYLOR) {
    result = -INF;
  } else if (x > S21_PI_2 - EPS_TEYLOR && x < S21_PI_2 + EPS_TEYLOR) {
    result = INF;
  } else {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}

long double s21_atan(double x) {
  long double increment, result;
  if (ISNAN(x)) {
    result = -NaN;
  } else if (ISINF(x)) {
    result = x == INF ? S21_PI_2 : -S21_PI_2;
  } else {
    int i = 1, sign = 1;
    if (x > 1 || x < -1) {
      long double exp = 1 / x;
      result = 1 / x;
      do {
        sign = -sign;
        exp /= x * x;
        increment = sign * exp / (2 * i + 1);
        result += increment;
        i++;
      } while (s21_fabs(increment) > S21_EPS);
      result = (x > 0 ? S21_PI_2 : -S21_PI_2) - result;
    } else {
      long double exp = x;
      result = x;
      do {
        sign = -sign;
        exp *= x * x;
        increment = sign * exp / (2 * i + 1);
        result += increment;
        i++;
      } while (s21_fabs(increment) > S21_EPS);
    }
  }
  return result;
}

long double s21_asin(double x) {
  long double result;
  if (x > 1 || x < -1) {
    result = -NaN;
  } else {
    if (x == 1 || x == -1) {
      result = x * S21_PI_2;
    } else {
      result = s21_atan(x / s21_sqrt(1 - x * x));
    }
  }
  return result;
}

long double s21_acos(double x) {
  long double result;
  if (x > 1 || x < -1) {
    result = NaN;
  } else {
    if (x == 0) {
      result = S21_PI_2;
    } else if (x == 1 || x == -1) {
      result = 0;
    } else {
      result = s21_atan(s21_sqrt(1 - x * x) / x);
    }
    if (x < 0) {
      result += S21_PI;
    }
  }
  return result;
}

long double s21_exp(double x) {
  long double result = 1;
  if (ISNAN(x)) {
    result = NaN;
  } else if (ISINF(x)) {
    result = x == INF ? INF : 0.;
  } else {
    long double temp_x = x, count = 1., temp_val = 1.;
    long double diff;
    int c = 0;
    temp_x *= x < 0. ? -1. : 1.;
    do {
      long double prev_result = result;
      temp_val *= temp_x / count++;
      result += temp_val;
      diff = s21_fabs(result - prev_result);
    } while (diff > EPS_TEYLOR && c++ < MAX_SIZE_TEYLOR);
    result = x < 0. ? 1.0 / result : result;
  }
  return result;
}

long double s21_log(double x) {
  long double result = 0;
  if (ISNAN(x)) {
    result = NaN;
  } else if (ISINF(x)) {
    result = x == -INF ? NaN : INF;
  } else if (x < 0.) {
    result = NaN;
  } else if (x < 1e-323) {
    result = -INF;
  } else {
    int c = 0;
    int pow_count = 0;
    while (x >= S21_EXP) {
      x /= S21_EXP;
      ++pow_count;
    }
    long double prev_result;
    do {
      prev_result = result;
      result += 2 * (x - s21_exp(result)) / (x + s21_exp(result));
    } while ((s21_fabs((result - prev_result)) * 2.) > EPS_TEYLOR &&
             c++ < MAX_SIZE_TEYLOR);
    result += pow_count;
  }
  return result;
}

long double s21_sqrt(double x) {
  long double result;
  if (ISNAN(x))
    result = NaN;
  else if (ISINF(x))
    result = x == INF ? INF : NaN;
  else if (x < 0.)
    result = NaN;
  else if (x < 1e-12)
    result = x;
  else {
    int n, d = 0, count = 0;
    double rough, pow = 1;
    if (x >= 1.) {
      int temp = (int)x;
      while (temp) {
        temp /= 10;
        ++d;
      }
      n = (d & 1) ? (d - 1) / 2 : (d - 2) / 2;
      for (int i = 0; i < n; ++i, pow *= 10.)
        ;
    } else {
      double temp = x;
      while (temp < 0.1) {
        temp *= 10.;
        --d;
      }
      n = (d & 1) ? (1 - d) / 2 : (2 - d) / 2;
      for (int i = 0; i < n; ++i, pow /= 10.)
        ;
    }
    rough = (d & 1) ? 2. * pow : 6. * pow;
    long double prev_y, y = rough;
    do {
      prev_y = y;
      y = 0.5 * (prev_y + x / prev_y);
    } while (s21_fabs(y - prev_y) > S21_EPS && count++ < MAX_SIZE);
    result = y;
  }
  return result;
}

long double PowInt(double base, long long exp) {
  long double result = 1.0;
  int minus_flag = exp < 0 ? 1 : 0;
  exp = minus_flag ? -exp : exp;
  while (exp != 0) {
    if ((exp & 1) != 0) {
      result *= base;
    }
    base *= base;
    exp >>= 1;
  }
  result = minus_flag ? 1. / result : result;
  return result;
}

long double PowDouble(double base, double exp) {
  long double result = 1.0;
  int minus_exp = exp < 0 ? 1 : 0;
  exp = minus_exp ? -exp : exp;
  long long exp_floor = (long long)exp;
  double exp_ost = exp - exp_floor;
  result = s21_exp(exp_ost * s21_log(base)) * PowInt(base, exp_floor);
  result = minus_exp ? 1. / result : result;
  return result;
}

long double s21_pow(double base, double exp) {
  long double result;
  if (ISNAN(exp) && s21_fabs(base - 1.) < 1e-16)
    result = 1.;
  else if (ISNAN(base) || ISNAN(exp))
    result = NaN;
  else if (ISINF(base) && ISINF(exp))
    result = exp == INF ? INF : 0.;
  else if (ISINF(base)) {
    if (exp < 0)
      result = 0.;
    else if (s21_fabs(exp) < 1e-16)
      result = 1.;
    else if (base == -INF && s21_fabs(exp - 1.) < 1e-16)
      result = -INF;
    else
      result = INF;
  } else if (ISINF(exp)) {
    if (exp == INF) {
      if (s21_fabs(base) > 1.)
        result = INF;
      else if (s21_fabs(s21_fabs(base) - 1.) < S21_EPS)
        result = 1.;
      else
        result = 0.;
    } else {
      if (s21_fabs(base) > 1.)
        result = 0.;
      else if (s21_fabs(s21_fabs(base) - 1.) < S21_EPS)
        result = 1.;
      else
        result = INF;
    }
  } else if (s21_fabs(exp - (long long)exp) < S21_EPS)
    result = PowInt(base, (long long)exp);
  else
    result = PowDouble(base, exp);
  return result;
}
