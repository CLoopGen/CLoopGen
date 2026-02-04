#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

size_t ord = 2000;
double h = 1.0e-6;
double hprev[2000];
double l[2001];
size_t i = 0;
size_t j = 0;
double hsum = 0.0;
double coeff1 = 0.0;

void init_vars() {
    hsum = 0.0;
    coeff1 = 0.0;
    for (size_t idx = 0; idx < ord; idx++) {
        hprev[idx] = 1.0 / (idx + 1);
    }
    l[0] = 1.0;
    for (size_t idx = 1; idx <= ord; idx++) {
        l[idx] = 0.0;
    }
}