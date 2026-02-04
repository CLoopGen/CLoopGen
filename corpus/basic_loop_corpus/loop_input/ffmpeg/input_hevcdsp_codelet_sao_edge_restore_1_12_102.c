#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
uint16_t *dst;
uint16_t *src;
int init_x;
int width;
int save_upper_left;
int save_upper_right;

void init_vars() {
    width = 65536; // ~256KB of data (65536 * sizeof(uint16_t) = 131072 bytes)
    init_x = 0;
    save_upper_left = 16;
    save_upper_right = 16;

    src = (uint16_t*)aligned_alloc(32, width * sizeof(uint16_t));
    dst = (uint16_t*)aligned_alloc(32, width * sizeof(uint16_t));

    for (int i = 0; i < width; i++) {
        src[i] = (uint16_t)(i & 0xFFFF);
    }
}