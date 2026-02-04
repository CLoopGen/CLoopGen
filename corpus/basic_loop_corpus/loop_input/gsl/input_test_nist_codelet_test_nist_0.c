#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t i;
double numacc2[1001];
double numacc3[1001];
double numacc4[1001];

void init_vars() {
    for (size_t j = 0; j < 1001; ++j) {
        numacc2[j] = 0.0;
        numacc3[j] = 0.0;
        numacc4[j] = 0.0;
    }
}