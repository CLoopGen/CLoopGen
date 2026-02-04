#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

double x;
int nexp;
double ex;
double xk;
double rk;
double sum;
int i;

void init_vars() {
    x = 1.5;
    nexp = 1000000;
    ex = 1.01;
    xk = 1000.0;
    rk = 100.0;
    sum = 0.5;
    i = 0;
}