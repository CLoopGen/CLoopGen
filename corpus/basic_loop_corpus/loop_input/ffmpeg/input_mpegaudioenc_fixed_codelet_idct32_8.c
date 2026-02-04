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

static int *out_buf;
static int *tab_buf;

int *out;
int *tab;
int i;

void init_vars() {
    const size_t data_size = 256 * 1024 * 1024; // 256 MB
    const size_t num_ints = data_size / sizeof(int);

    out_buf = (int*)calloc(num_ints, sizeof(int));
    tab_buf = (int*)calloc(num_ints, sizeof(int));

    if (!out_buf || !tab_buf) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    out = out_buf;
    tab = tab_buf;

    for (size_t idx = 0; idx < num_ints; idx++) {
        tab[idx] = rand();
    }
}