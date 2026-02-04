#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src;
int width;
int x;
int mask;
int dst_x;
int j;
int b;

static uint8_t *src_buffer;
static uint8_t *dst_buffer;
static size_t buffer_size;

void init_vars() {
    buffer_size = 128 * 1024 * 1024; // 128 MB

    src_buffer = aligned_alloc(32, buffer_size);
    dst_buffer = aligned_alloc(32, buffer_size);

    if (!src_buffer || !dst_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < buffer_size; i++) {
        src_buffer[i] = rand() & 0xFF;
        dst_buffer[i] = 0;
    }

    src = src_buffer;
    dst = dst_buffer;
    width = buffer_size * 8; 
    mask = 0xFF; 
    dst_x = 0;
}