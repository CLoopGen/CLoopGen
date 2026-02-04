#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef short IDWTELEM;
typedef int x86_reg;

IDWTELEM *b;
int w_r;
int i;
IDWTELEM *dst;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime (~0.01 sec on modern CPU)
    b = (IDWTELEM*)aligned_alloc(32, data_size);
    dst = (IDWTELEM*)aligned_alloc(32, data_size);

    if (!b || !dst) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / sizeof(IDWTELEM); idx++) {
        b[idx] = (IDWTELEM)(idx % 32768);
        dst[idx] = (IDWTELEM)((idx + 1) % 32768);
    }

    w_r = (data_size / sizeof(IDWTELEM)) - 1; // Ensure b[i+1] access is valid
    i = 0;
}