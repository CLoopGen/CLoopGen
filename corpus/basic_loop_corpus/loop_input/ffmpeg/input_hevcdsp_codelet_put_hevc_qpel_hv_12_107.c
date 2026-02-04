#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 128;
int width = 64;
int x = 0;
int y = 0;

int8_t filter_data[8] = {1, -1, 2, -2, 1, -1, 2, -2};
int8_t *filter = filter_data;

uint16_t src_data[256 * 256];
uint16_t *src = src_data;

ptrdiff_t srcstride = 256;

int16_t tmp_data[64 * (128 + 7)];
int16_t *tmp = tmp_data;

void init_vars() {
    for (int i = 0; i < 256 * 256; i++) {
        src_data[i] = rand() % 1024;
    }
    for (int i = 0; i < 64 * (128 + 7); i++) {
        tmp_data[i] = 0;
    }
}