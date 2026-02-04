#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
ptrdiff_t stride;
uint8_t *cm;
uint8_t *top;
int y;

static uint8_t *src_buffer;
static uint8_t *cm_buffer;
static uint8_t *top_buffer;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of input data
    const int height = 4;

    src_buffer = aligned_alloc(32, data_size);
    cm_buffer = aligned_alloc(32, 256);
    top_buffer = aligned_alloc(32, 4);

    if (!src_buffer || !cm_buffer || !top_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        src_buffer[i] = rand() & 0xFF;
    }
    for (int i = 0; i < 256; i++) {
        cm_buffer[i] = rand() & 0xFF;
    }
    for (int i = 0; i < 4; i++) {
        top_buffer[i] = rand() & 0xFF;
    }

    stride = 16; 
    src = src_buffer + 1; 
    cm = cm_buffer;
    top = top_buffer;
    y = 0;
}