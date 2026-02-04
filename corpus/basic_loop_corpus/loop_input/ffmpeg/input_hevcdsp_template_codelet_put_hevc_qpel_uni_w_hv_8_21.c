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

uint8_t src_buffer[256 * 256];
uint8_t *src = src_buffer;

ptrdiff_t srcstride = 256;

int16_t tmp_buffer[64 * (64 + 7)];
int16_t *tmp = tmp_buffer;

void init_vars() {
    for (int i = 0; i < 8; i++) {
        filter_data[i] = (int8_t)(i + 1);
    }

    for (int i = 0; i < 256 * 256; i++) {
        src_buffer[i] = (uint8_t)(i % 256);
    }

    for (int i = 0; i < 64 * (64 + 7); i++) {
        tmp_buffer[i] = 0;
    }

    height = 64;
    width = 64;
    src = src_buffer + 3 * srcstride + 3;
    tmp = tmp_buffer;
}