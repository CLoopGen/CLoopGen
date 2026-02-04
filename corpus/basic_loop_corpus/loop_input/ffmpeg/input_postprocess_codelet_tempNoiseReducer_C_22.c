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
    size_t total_size = 1 << 20; // 1MB of data
    stride = 128; // Ensure sufficient width to avoid boundary issues with 8x8 blocks

    src_buffer = (uint8_t*)calloc(total_size, sizeof(uint8_t));
    tempBlurred_buffer = (uint8_t*)calloc(total_size, sizeof(uint8_t));

    if (!src_buffer || !tempBlurred_buffer) {
        exit(1);
    }

    src = src_buffer;
    tempBlurred = tempBlurred_buffer;

    for (size_t i = 0; i < total_size; i++) {
        src_buffer[i] = rand() & 0xFF;
        tempBlurred_buffer[i] = rand() & 0xFF;
    }
}