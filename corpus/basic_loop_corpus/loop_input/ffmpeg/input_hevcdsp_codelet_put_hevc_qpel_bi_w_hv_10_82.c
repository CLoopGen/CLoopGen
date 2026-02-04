#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x;
int y;

int8_t filter_data[8] = {1, -2, 3, -4, 5, -6, 7, -8};
int8_t *filter = filter_data;

uint16_t src_data[2048 * 2048];
uint16_t *src = src_data;
ptrdiff_t srcstride = 2048;

int16_t tmp_data[64 * (1024 + 7)];
int16_t *tmp = tmp_data;

void init_vars() {
    for (int i = 0; i < 8; i++) {
        filter[i] = (int8_t)(i % 2 == 0 ? 8 - i : i - 8);
    }

    for (int i = 0; i < 2048 * 2048; i++) {
        src_data[i] = (uint16_t)(i % 512);
    }

    for (int i = 0; i < 64 * (height + 7); i++) {
        tmp_data[i] = 0;
    }
}