#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int w = 1024;
int h = 512;
int color = 0x7FFF;
int stride = 2048;
int i;
int j;
uint16_t *dst2;

void init_vars() {
    dst = (uint8_t *)aligned_alloc(64, (size_t)stride * h);
    if (!dst) {
        exit(1);
    }
}