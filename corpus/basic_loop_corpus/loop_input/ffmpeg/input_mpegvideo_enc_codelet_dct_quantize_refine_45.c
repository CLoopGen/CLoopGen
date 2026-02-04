#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *orig;
int16_t rem[64];
int i;
int dc;

void init_vars() {
    const size_t data_size = 64;
    orig = aligned_alloc(32, data_size * sizeof(int16_t));
    if (!orig) {
        exit(1);
    }
    dc = 1000;
    for (size_t idx = 0; idx < data_size; ++idx) {
        orig[idx] = (int16_t)(idx * 3);
    }
}