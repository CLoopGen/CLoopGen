#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
int stride;
uint8_t *tempBlurred;
int y;

static uint8_t *src_buffer;
static uint8_t *tempBlurred_buffer;

void init_vars() {
    stride = 128;
    int total_elements = stride * 16;
    size_t total_bytes = total_elements * sizeof(uint8_t);

    src_buffer = aligned_alloc(32, total_bytes);
    tempBlurred_buffer = aligned_alloc(32, total_bytes);

    if (!src_buffer || !tempBlurred_buffer) {
        exit(1);
    }

    for (int i = 0; i < total_elements; i++) {
        src_buffer[i] = rand() & 0xFF;
        tempBlurred_buffer[i] = rand() & 0xFF;
    }

    src = src_buffer + stride * 4;
    tempBlurred = tempBlurred_buffer + stride * 4;
}