#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int bitinv32[32];
int *out;
int *tab;
int i;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data (262144 integers, ~1M bytes)

    out = (int*)aligned_alloc(32, data_size * sizeof(int));
    tab = (int*)aligned_alloc(32, data_size * sizeof(int));

    if (!out || !tab) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        tab[idx] = rand();
    }

    for (int idx = 0; idx < 32; ++idx) {
        bitinv32[idx] = 31 - idx;
    }
}