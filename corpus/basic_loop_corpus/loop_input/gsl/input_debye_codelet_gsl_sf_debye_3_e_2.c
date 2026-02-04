#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double x = 0.5;
int nexp = 1000000;
double ex = 1.2;
double xk = 100000.0;
double rk = 100000.0;
double sum = 1.0;
int i;

void init_vars() {
    x = 0.5;
    nexp = 1000000;
    ex = 1.2;
    xk = 100000.0;
    rk = 100000.0;
    sum = 1.0;
}