#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double eps;
int q;
double eqq;

void init_vars() {
    eps = 1e-15;
    q = 0;
    eqq = 1.0;
}