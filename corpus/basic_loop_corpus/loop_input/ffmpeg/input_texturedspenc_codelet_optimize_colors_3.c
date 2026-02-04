#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *block;
ptrdiff_t stride;
int cov[6];
int mu[3];
int x;
int y;

void init_vars() {
    mu[0] = 128;
    mu[1] = 128;
    mu[2] = 128;

    for (int i = 0; i < 6; i++) {
        cov[i] = 0;
    }

    stride = 4;
    int total_elements = 256 * (1 << 20) / sizeof(uint8_t); // ~256MB of data
    block = (uint8_t*)aligned_alloc(32, total_elements * sizeof(uint8_t));
    if (!block) {
        exit(1);
    }

    for (int i = 0; i < total_elements; i++) {
        block[i] = rand() % 256;
    }
}