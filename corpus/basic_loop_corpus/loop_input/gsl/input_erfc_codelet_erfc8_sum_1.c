#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double x = 1.5;
double den = 0.0;
int i;

double Q[6];

void init_vars() {
    x = 1.5;
    den = 1.0;
    for (i = 0; i < 6; ++i) {
        Q[i] = (double)(i + 1) * 0.5;
    }
}