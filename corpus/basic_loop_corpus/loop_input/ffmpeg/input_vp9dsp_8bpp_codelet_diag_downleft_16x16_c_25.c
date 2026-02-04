#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *top;
int i;
uint8_t v[15];

static uint8_t *buffer;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB of input data for ~0.01 sec runtime
    buffer = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!buffer) {
        exit(1);
    }

    for (size_t j = 0; j < data_size; j++) {
        buffer[j] = (uint8_t)((j * 71 + 13) % 256);
    }

    top = buffer;

    for (i = 0; i < 13; i++) {
        v[i] = 0;
    }
}