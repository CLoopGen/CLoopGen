#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double x;
int nexp;
double ex;
double sum;
double xk;
double rk;
int i;

void init_vars() {
    x = 0.5;
    nexp = 1000000;
    ex = 1.000001;
    sum = 1.0;
    xk = 100000.0;
    rk = (double)nexp;
}