#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *d;
uint8_t *top;
ptrdiff_t stride;
int x;
int y;

static uint8_t *d_buffer;
static uint8_t *top_buffer;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB of data
    stride = 8;

    d_buffer = calloc(data_size, sizeof(uint8_t));
    top_buffer = calloc(data_size, sizeof(uint8_t));

    if (!d_buffer || !top_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    d = d_buffer;
    top = top_buffer;

    for (size_t i = 0; i < data_size; i++) {
        top[i] = rand() & 0xFF;
    }
}