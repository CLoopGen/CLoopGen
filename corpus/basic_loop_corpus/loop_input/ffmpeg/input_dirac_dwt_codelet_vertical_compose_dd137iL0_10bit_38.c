#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int width;
int i;
int32_t *b0;
int32_t *b1;
int32_t *b2;
int32_t *b3;
int32_t *b4;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~256 MB for five arrays (each ~51.2 MB)
    width = data_size / sizeof(int32_t);

    b0 = aligned_alloc(32, data_size);
    b1 = aligned_alloc(32, data_size);
    b2 = aligned_alloc(32, data_size);
    b3 = aligned_alloc(32, data_size);
    b4 = aligned_alloc(32, data_size);

    if (!b0 || !b1 || !b2 || !b3 || !b4) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand(time(NULL));
    for (int j = 0; j < width; j++) {
        b0[j] = rand();
        b1[j] = rand();
        b2[j] = rand();
        b3[j] = rand();
        b4[j] = rand();
    }
}