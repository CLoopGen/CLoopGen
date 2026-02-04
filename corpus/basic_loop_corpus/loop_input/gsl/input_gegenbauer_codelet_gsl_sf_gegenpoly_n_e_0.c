#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int n = 10000000;
double lambda = 2.5;
double x = 0.7;
int k;
double gkm2 = 1.0;
double gkm1 = 2.0;
double gk;

void init_vars() {
    n = 10000000;
    lambda = 2.5;
    x = 0.7;
    gkm2 = 1.0;
    gkm1 = 2.0;
}