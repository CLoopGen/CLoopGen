#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *b;
int16_t *temp;
int w2;
int x;

static size_t data_size;

void init_vars() {
    data_size = 64 * 1024 * 1024; // ~128MB of total data (adjustable for ~0.01s runtime)
    w2 = data_size / sizeof(int16_t);

    b = aligned_alloc(32, data_size * 2);
    temp = aligned_alloc(32, data_size * 2);

    if (!b || !temp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < w2 * 2; i++) {
        b[i] = rand() % 1000;
    }
}