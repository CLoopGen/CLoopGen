#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 64;
int width = 64;
int x;
int y;
int8_t filter_data[8] = {1, -2, 3, -4, 5, -6, 7, -8};
uint16_t src_data[256 * 256];
int16_t tmp_data[256 * 256];
int8_t *filter = filter_data;
uint16_t *src = src_data;
ptrdiff_t srcstride = 256;
int16_t *tmp = tmp_data;

void init_vars() {
    for (int i = 0; i < 256 * 256; i++) {
        src_data[i] = (i * 17) & 0x3FF;
    }
    for (int i = 0; i < 256 * 256; i++) {
        tmp_data[i] = 0;
    }
}