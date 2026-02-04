#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double cheb24[25];
double moment[25];
double res24;
size_t i;

void init_vars() {
    res24 = 0.0;
    for (i = 0; i < 25; i++) {
        cheb24[i] = 1.0;
        moment[i] = 2.0;
    }
}