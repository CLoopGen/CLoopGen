#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double b;
double x;
double a0;
double epsb;
double n;
double Ma0np1;
double Ma0n;
double Ma0nm1;

void init_vars() {
    b = 1000.0;
    x = 2.5;
    a0 = 2000.0;
    epsb = 1.0;
    n = a0 + epsb - 1.0;
    Ma0np1 = 1.0;
    Ma0n = 1.0;
    Ma0nm1 = 0.0;
}