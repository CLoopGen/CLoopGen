#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
ptrdiff_t stride = 64;
uint8_t *src;
uint8_t *left;
int bottom_left_size = 1000000;

uint8_t src_data[256 * 1024 * 1024];
uint8_t left_data[256 * 1024 * 1024];

void init_vars() {
    src = src_data + 64;
    left = left_data + 16;
    for (int j = 0; j < 256 * 1024 * 1024; j++) {
        src_data[j] = (uint8_t)(j & 0xFF);
        left_data[j] = 0;
    }
}