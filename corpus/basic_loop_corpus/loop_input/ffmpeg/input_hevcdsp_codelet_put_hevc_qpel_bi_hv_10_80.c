#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x;
int y;

int8_t filter_data[8] = {1, -3, 5, -7, 7, -5, 3, -1};
int8_t *filter = filter_data;

uint16_t src_data[1024 * (1024 + 14)] = {0};
uint16_t *src = src_data;

ptrdiff_t srcstride = 1024;

int16_t tmp_data[64 * 1031] = {0};
int16_t *tmp = tmp_data;

void init_vars() {
    for (int i = 0; i < 8; i++) {
        filter[i] = (int8_t)(i * 2 - 7);
    }

    for (int i = 0; i < 1024 * (1024 + 14); i++) {
        src_data[i] = (uint16_t)(i % 512);
    }

    for (int i = 0; i < 64 * 1031; i++) {
        tmp_data[i] = 0;
    }
}