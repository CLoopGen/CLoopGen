#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double x[9];
double norm;
int i;

void init_vars() {
    for (int j = 0; j < 9; ++j) {
        x[j] = (double)(j + 1) * 1.5;
    }
}