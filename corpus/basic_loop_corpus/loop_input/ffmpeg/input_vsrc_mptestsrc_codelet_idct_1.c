#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double c[64];
int src[64];
int i;
int j;
int k;
double tmp[64];

void init_vars() {
    for (int idx = 0; idx < 64; idx++) {
        c[idx] = (double)(idx + 1);
        src[idx] = idx * 2;
        tmp[idx] = 0.0;
    }
    i = 0;
    j = 0;
    k = 0;
}