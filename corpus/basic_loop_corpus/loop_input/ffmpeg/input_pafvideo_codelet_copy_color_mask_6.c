#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int width;
uint8_t mask;
uint8_t color;
int i;

void init_vars() {
    width = 1 << 20;
    dst = (uint8_t *)aligned_alloc(32, width * 2);
    if (!dst) {
        exit(1);
    }
    mask = 0xFF;
    color = 0x7F;
    for (int j = 0; j < width * 2; j++) {
        dst[j] = 0;
    }
}