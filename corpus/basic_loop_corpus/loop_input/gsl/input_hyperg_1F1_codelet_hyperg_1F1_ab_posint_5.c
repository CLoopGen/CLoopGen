#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int b;
double x;
int a0;
int n;
double Ma0np1;
double Ma0n;
double Ma0nm1;

void init_vars() {
    b = 1000;
    x = 0.375;
    a0 = 2000;
    n = a0 - 1;
    Ma0np1 = 1.0;
    Ma0n = 0.5;
    Ma0nm1 = 0.0;
}