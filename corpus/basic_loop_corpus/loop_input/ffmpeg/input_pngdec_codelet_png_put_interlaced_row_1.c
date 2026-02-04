#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

uint8_t *dst;
int width;
uint8_t *src;
int x;
int mask;
int dsp_mask;
int j;
int src_x;
int b;

void init_vars() {
    width = 64 * 1024 * 8;  // 64KB in bits, ensures loop runs ~0.01s on modern CPU
    dst = (uint8_t*)aligned_alloc(32, width / 8);
    src = (uint8_t*)aligned_alloc(32, width / 8);

    if (!dst || !src) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < width / 8; i++) {
        dst[i] = 0xFF;
        src[i] = rand() & 0xFF;
    }

    mask = 0xAA;
    dsp_mask = 0xCC;
    src_x = 0;
    x = 0;
    j = 0;
    b = 0;
}