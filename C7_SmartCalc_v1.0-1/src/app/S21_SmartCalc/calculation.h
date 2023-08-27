#ifndef CALCULATION_H
#define CALCULATION_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"

/**
 *takes a stack of stack_s type with lexemes present as a Polish notation and a
 *double type as an input and returns a revesed Polish notation and 'x' replaced
 *with the given number, based on it as a stack of s_stack type
 */
stack_s *notation_reverse(stack_s *stack, double a);
double calculate(stack_s *notation);
int run_operation(char *operation, num_stack_s *numbers);
double annuity_payment(double s, double p, double n);
double differentiated_interest(double s, double p, double n, int md, int yd);
double interest_sum(double s, double p);

#endif
