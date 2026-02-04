#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

double c4[4][4];
double block2[64];
double block3[64];
double sum;
int i;
int j;
int k;

void init_vars() {
    for (int ii = 0; ii < 4; ++ii) {
        for (int jj = 0; jj < 4; ++jj) {
            c4[ii][jj] = sin(ii * 4 + jj + 1);
        }
    }

    for (int idx = 0; idx < 64; ++idx) {
        block2[idx] = (double)(idx + 1) / 67.0;
        block3[idx] = 0.0;
    }

    sum = 0.0;
    i = 0;
    j = 0;
    k = 0;
}