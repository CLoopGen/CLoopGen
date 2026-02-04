#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double r;
double rk;
double sum;
int k;

void init_vars() {
    r = 0.5;
    rk = 1.0;
    sum = 0.0;
    k = 0;
}