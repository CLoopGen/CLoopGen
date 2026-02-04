#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

double v[28];
double d[25];
double d1[25];
double d2[25];
size_t noeq;
double par2;
double par22;
double ac;
double as;
double an2;
double an;
size_t k;

void init_vars() {
    noeq = 24;
    par2 = 1.5;
    par22 = 3.0;
    ac = 0.25;
    as = 2.75;
    an = 1.0;

    for (int i = 0; i < 28; i++) {
        v[i] = 0.0;
    }
    for (int i = 0; i < 25; i++) {
        d[i] = 0.0;
        d1[i] = 0.0;
        d2[i] = 0.0;
    }

    k = 0;
    an2 = an * an;
}