#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 64;
int width = 64;
int x;
int y;

int8_t filter_data[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int8_t *filter = filter_data;

uint8_t *src;
int16_t *tmp;

ptrdiff_t srcstride = 64;

uint8_t src_buffer[256 * 1024]; // ~256KB buffer to control data size
int16_t tmp_buffer[64 * (64 + 12)]; // enough for all tmp rows with margin

void init_vars() {
    src = src_buffer + 3; // offset to allow x - 3 access without underflow
    tmp = tmp_buffer;

    for (int i = 0; i < 8; i++) {
        filter_data[i] = (int8_t)(i + 1);
    }

    for (size_t i = 0; i < sizeof(src_buffer); i++) {
        src_buffer[i] = (uint8_t)(i % 256);
    }

    for (size_t i = 0; i < 64 * (height + 7); i++) {
        tmp_buffer[i] = 0;
    }
}