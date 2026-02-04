#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double v[28];
double par2;
double par22;
double ac;
double as;
size_t k;
double an;

void init_vars() {
    par2 = 1.5;
    par22 = 2.0;
    ac = 0.3;
    as = 0.7;
    an = 3.0;

    for (int i = 0; i < 28; i++) {
        v[i] = 1.0 + i * 0.1;
    }
}