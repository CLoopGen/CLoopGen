#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x;
int y;

int8_t filter_data[8] = {16, -8, 4, -2, 1, -1, 2, -1};
int8_t *filter = filter_data;

uint16_t src_data[2048 * 2048];
uint16_t *src = src_data;

ptrdiff_t srcstride = 2048;

int16_t tmp_data[64 * (1024 + 7)];
int16_t *tmp = tmp_data;

void init_vars() {
    for (int i = 0; i < 2048 * 2048; i++) {
        src_data[i] = rand() & 0x3FF;
    }
    for (int i = 0; i < 64 * (1024 + 7); i++) {
        tmp_data[i] = 0;
    }
}