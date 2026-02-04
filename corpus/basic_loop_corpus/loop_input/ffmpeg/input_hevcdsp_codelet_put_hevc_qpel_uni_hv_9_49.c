#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int height = 1024;
int width = 1024;
int x;
int y;

int8_t filter_data[8] = {1, -1, 2, -2, 1, -1, 2, -2};
int8_t *filter = filter_data;

uint16_t src_data[2048 * 1024];
uint16_t *src = src_data;
ptrdiff_t srcstride = 1024;

int16_t tmp_data[65536];
int16_t *tmp = tmp_data;

void init_vars() {
    for (int i = 0; i < 2048 * 1024; i++) {
        src_data[i] = i & 0xFFFF;
    }
    for (int i = 0; i < 65536; i++) {
        tmp_data[i] = 0;
    }
}