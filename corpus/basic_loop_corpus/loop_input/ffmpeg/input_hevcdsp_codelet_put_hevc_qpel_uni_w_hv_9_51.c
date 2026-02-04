#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 512;
int x;
int y;

int8_t filter_data[8] = {1, -3, 4, -2, 5, -6, 2, 8};
int8_t *filter = filter_data;

uint16_t src_data[1024 * (512 + 8)] = {0};
uint16_t *src = src_data;

ptrdiff_t srcstride = 512 + 8;

int16_t tmp_data[1024 * 64] = {0};
int16_t *tmp = tmp_data;

void init_vars() {
    for (int i = 0; i < 8; i++) {
        filter[i] = (int8_t)(i * 2 - 7);
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width + 8; j++) {
            src[i * (width + 8) + j] = (uint16_t)(j % 257);
        }
    }

    src = src_data;
    tmp = tmp_data;
}