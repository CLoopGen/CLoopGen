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
uint8_t src_data[256 * 1024]; // ~256KB source data

int16_t *tmp;
int16_t tmp_data[64 * (64 + 7)]; // enough for each row of tmp

ptrdiff_t srcstride = 64;

void init_vars() {
    src = src_data + 3; // offset to allow x - 3 access without underflow
    tmp = tmp_data;

    for (int i = 0; i < sizeof(src_data); i++) {
        src_data[i] = (i * 17) % 251;
    }

    for (int i = 0; i < 8; i++) {
        filter_data[i] = (int8_t)(5 - i);
    }
}