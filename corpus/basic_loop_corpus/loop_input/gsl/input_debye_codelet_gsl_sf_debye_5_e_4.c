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
    x = 0.01;
    nexp = 2000000;
    ex = 1.05;
    xk = 20.0;
    rk = 2000000.0;
    sum = 1.0;
}