#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x;
int y;

int8_t filter_data[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int8_t *filter = filter_data;

uint16_t src_data[1024 * (1024 + 8)] = {0};
uint16_t *src = src_data;
ptrdiff_t srcstride = 1024 + 8;

int16_t tmp_data[1024 * 1024];
int16_t *tmp = tmp_data;

void init_vars() {
    for (int i = 0; i < 8; i++) {
        filter[i] = (int8_t)(i + 1);
    }

    const int padded_width = width + 8;
    for (int i = 0; i < height + 7; i++) {
        for (int j = 0; j < padded_width; j++) {
            src[i * padded_width + j] = (uint16_t)((i + j) & 0x3FF);
        }
    }

    for (int i = 0; i < height * 1024; i++) {
        tmp[i] = 0;
    }
}