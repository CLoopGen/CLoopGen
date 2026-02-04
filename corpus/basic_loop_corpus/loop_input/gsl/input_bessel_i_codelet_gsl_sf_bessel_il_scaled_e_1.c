#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int l;
double x;
int LMAX;
double iellp1;
double iell;
double iellm1;
int ell;

void init_vars() {
    l = 1000;
    x = 1.5;
    LMAX = 1000000;
    iellp1 = 1.0;
    iell = 2.0;
    iellm1 = 0.0;
    ell = 0;
}