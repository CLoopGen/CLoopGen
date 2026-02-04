#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int i;
int64_t sysErr[64];
int64_t sysErrMax;
int64_t err2_matrix[64];
int64_t err2_max;

void init_vars() {
    for (int j = 0; j < 64; j++) {
        sysErr[j] = (rand() % 2000000) - 1000000;
        err2_matrix[j] = (rand() % 2000000) - 1000000;
    }
    sysErrMax = 0;
    err2_max = 0;
    i = 0;
}