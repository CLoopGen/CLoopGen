#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double x;
int nexp;
double ex;
double xk;
double rk;
double sum;
int i;

void init_vars() {
    x = 0.5;
    nexp = 1000000;
    ex = 1.000001;
    xk = 1000000.0;
    rk = 1000000.0;
    sum = 1.0;
    i = 0;
}