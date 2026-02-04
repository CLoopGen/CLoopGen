#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 512;
int x;
int y;

int8_t filter_data[8] = {1, -3, 4, -6, 7, -3, 2, -1};
int8_t *filter = filter_data;

uint16_t src_data[1024 * (512 + 8)] __attribute__((aligned(32)));
uint16_t *src = src_data;

ptrdiff_t srcstride = 512 + 8;

int16_t tmp_data[1024 * 64] __attribute__((aligned(32)));
int16_t *tmp = tmp_data;

void init_vars() {
    for (int i = 0; i < 8; i++) {
        filter[i] = (int8_t)(i * 2 - 7);
    }

    int total_elements = height * (width + 8);
    for (int i = 0; i < total_elements; i++) {
        src_data[i] = (uint16_t)(i & 0x3FF);
    }

    total_elements = height * 64;
    for (int i = 0; i < total_elements; i++) {
        tmp_data[i] = 0;
    }
}