#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
ptrdiff_t stride;
int i;
unsigned int dc0;

static uint8_t data[1 << 24]; // 16MB of input data

void init_vars() {
    size_t total_size = 1 << 24;
    stride = 1 << 20; // 1MB stride

    for (size_t idx = 0; idx < total_size; ++idx) {
        data[idx] = rand() % 256;
    }

    src = &data[stride]; // Point src such that accessing [-1] is valid
    i = 0;
    dc0 = 0;
}