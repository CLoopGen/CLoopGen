#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x = 0;
int y = 0;

int8_t filter_data[8] = {1, -2, 3, -4, 5, -6, 7, -8};
int8_t *filter = filter_data;

uint16_t src_data[1024 * (1024 + 8)] = {0};
uint16_t *src = src_data;

ptrdiff_t srcstride = 1024 + 8;

int16_t tmp_data[64 * 1032] = {0};
int16_t *tmp = tmp_data;

void init_vars() {
    for (int i = 0; i < 8; i++) {
        filter[i] = (int8_t)(i + 1) * ((i % 2) ? -1 : 1);
    }

    for (int i = 0; i < height + 8; i++) {
        for (int j = 0; j < width + 8; j++) {
            src[i * (width + 8) + j] = (uint16_t)((i + j) & 0x3FF);
        }
    }

    src = src_data;
    tmp = tmp_data;
}