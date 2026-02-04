#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float **w;
int m = 4095;
int n = 4095;
int i;
int j;

void init_vars() {
    w = (float**)calloc(m + 1, sizeof(float*));
    for (int idx = 0; idx <= m; idx++) {
        w[idx] = (float*)calloc(n + 1, sizeof(float));
    }
}