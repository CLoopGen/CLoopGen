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
    const size_t data_size = 1 << 20; // 1MB of data

    src_buffer = aligned_alloc(32, data_size);
    cm_buffer = aligned_alloc(32, 256);
    top_buffer = aligned_alloc(32, 16);

    for (size_t i = 0; i < 256; i++) {
        cm_buffer[i] = rand() % 256;
    }
    for (size_t i = 0; i < 16; i++) {
        top_buffer[i] = rand() % 256;
    }
    for (size_t i = 0; i < data_size; i++) {
        src_buffer[i] = rand() % 256;
    }

    src = src_buffer + 1; 
    stride = 16;
    cm = cm_buffer;
    top = top_buffer;
}