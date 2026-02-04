#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int N = 10000000;
double x = 2.718281828459045;
double bigGsum = 0.0;
double term = 1.0;
int k;

void init_vars() {
    N = 10000000;
    x = 2.718281828459045;
    bigGsum = 0.0;
    term = 1.0;
    k = 0;
}