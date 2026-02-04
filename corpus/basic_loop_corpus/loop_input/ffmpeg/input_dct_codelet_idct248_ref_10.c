#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

double c8[8][8];
double block1[64];
double block2[64];
double sum;
int i;
int j;
int k;

void init_vars() {
    for (int idx = 0; idx < 8; ++idx) {
        for (int jdx = 0; jdx < 8; ++jdx) {
            c8[idx][jdx] = (double)(idx * 8 + jdx + 1);
        }
    }

    for (int idx = 0; idx < 64; ++idx) {
        block1[idx] = (double)(idx + 1);
        block2[idx] = 0.0;
    }

    sum = 0.0;
    i = 0;
    j = 0;
    k = 0;
}