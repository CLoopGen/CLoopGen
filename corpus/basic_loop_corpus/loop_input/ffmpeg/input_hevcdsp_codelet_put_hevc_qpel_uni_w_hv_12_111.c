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

uint16_t src_data[2048 * 2048];
uint16_t *src = src_data;

ptrdiff_t srcstride = 2048;

int16_t tmp_data[64 * (1024 + 7)];
int16_t *tmp = tmp_data;

void init_vars() {
    for (int i = 0; i < 8; i++) {
        filter_data[i] = (int8_t)(i & 1 ? -(i + 1) : (i + 1));
    }

    for (int i = 0; i < 2048 * 2048; i++) {
        src_data[i] = (uint16_t)(i % 32768);
    }

    for (int i = 0; i < 64 * (1024 + 7); i++) {
        tmp_data[i] = 0;
    }

    height = 1024;
    width = 1024;
    x = 0;
    y = 0;
    src = src_data + 3 * 2048 + 3;
    tmp = tmp_data;
    srcstride = 2048;
}