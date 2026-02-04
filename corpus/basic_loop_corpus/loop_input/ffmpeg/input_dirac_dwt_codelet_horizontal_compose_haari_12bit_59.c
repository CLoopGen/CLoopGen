#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *b;
int32_t *temp;
int w2;
int x;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data to ensure ~0.01s runtime
    w2 = data_size / sizeof(int32_t); // number of int32_t elements per segment

    b = (int32_t*)aligned_alloc(32, 2 * w2 * sizeof(int32_t));
    temp = (int32_t*)aligned_alloc(32, 2 * w2 * sizeof(int32_t));

    if (!b || !temp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < 2 * w2; i++) {
        b[i] = rand() % 1000;
        temp[i] = 0;
    }
}