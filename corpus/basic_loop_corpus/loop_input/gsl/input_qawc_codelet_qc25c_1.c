#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double cheb12[13] = {0.0};
double moment[25] = {0.0};
double res12 = 0.0;
size_t i = 0;

void init_vars() {
    for (i = 0; i < 13; i++) {
        cheb12[i] = (double)(i + 1);
        moment[i] = (double)(2 * i + 1);
    }
    res12 = 0.0;
}