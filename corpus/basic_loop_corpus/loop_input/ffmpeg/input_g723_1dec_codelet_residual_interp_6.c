#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *out;
int gain;
int *rseed;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of output data
    out = (int16_t *)aligned_alloc(32, data_size);
    if (!out) {
        exit(1);
    }

    rseed = (int *)malloc(sizeof(int));
    if (!rseed) {
        exit(1);
    }

    *rseed = 12345;
    gain = 16384; // example gain value, scaled appropriately for fixed-point shift
}