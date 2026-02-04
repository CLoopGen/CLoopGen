#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src1;
uint8_t *src2;
int w;
int h;
int stride;
uint32_t *sq;
int acc;
int x;
int y;

void init_vars() {
    w = 4096;
    h = 64;
    stride = w;
    size_t total_size = (size_t)h * stride;

    src1 = (uint8_t*)calloc(total_size, sizeof(uint8_t));
    src2 = (uint8_t*)calloc(total_size, sizeof(uint8_t));

    sq = (uint32_t*)calloc(512, sizeof(uint32_t));
    for (int i = 0; i < 512; i++) {
        sq[i] = (uint32_t)(i * i);
    }

    acc = 0;

    if (!src1 || !src2 || !sq) {
        exit(1);
    }
}