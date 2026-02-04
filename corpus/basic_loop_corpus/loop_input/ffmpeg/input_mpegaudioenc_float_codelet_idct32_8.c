#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int bitinv32[32] = {
    31, 30, 29, 28, 27, 26, 25, 24,
    23, 22, 21, 20, 19, 18, 17, 16,
    15, 14, 13, 12, 11, 10, 9, 8,
    7, 6, 5, 4, 3, 2, 1, 0
};

int *out;
int *tab;
int i;

void init_vars() {
    const size_t data_size = 268435456; // 256 MB
    out = (int *)aligned_alloc(32, data_size);
    tab = (int *)aligned_alloc(32, data_size);

    if (!out || !tab) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size / sizeof(int); idx++) {
        tab[idx] = rand();
    }
}