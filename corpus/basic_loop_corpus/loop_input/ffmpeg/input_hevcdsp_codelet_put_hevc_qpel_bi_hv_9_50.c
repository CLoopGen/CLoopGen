#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 512;
int width = 1024;
int x;
int y;

int8_t filter_data[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int8_t *filter = filter_data;

uint16_t src_data[2048 * 1024]; // Large enough to handle offsets and strides
uint16_t *src = src_data;

ptrdiff_t srcstride = 1024;

int16_t tmp_data[64 * 512];
int16_t *tmp = tmp_data;

void init_vars() {
    for (int i = 0; i < 8; ++i) {
        filter[i] = (int8_t)(i + 1);
    }

    for (int i = 0; i < 2048 * 1024; ++i) {
        src_data[i] = (uint16_t)(i % 512);
    }

    for (int i = 0; i < 64 * 512; ++i) {
        tmp_data[i] = 0;
    }
}