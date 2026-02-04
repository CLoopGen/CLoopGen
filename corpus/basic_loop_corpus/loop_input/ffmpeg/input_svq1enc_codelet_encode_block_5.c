#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *ref;
int stride;
int y;
int x;
int best_score;
int block_sum[7];
int w;
int h;
int16_t (*block)[256];

void init_vars() {
    w = 512;
    h = 512;
    stride = 512;
    best_score = 0;
    for (int i = 0; i < 7; i++) {
        block_sum[i] = 0;
    }

    src = (uint8_t *)aligned_alloc(32, stride * h * sizeof(uint8_t));
    ref = (uint8_t *)aligned_alloc(32, stride * h * sizeof(uint8_t));
    block = (int16_t (*)[256])aligned_alloc(32, w * h * sizeof(int16_t));

    for (int i = 0; i < stride * h; i++) {
        src[i] = rand() % 256;
        ref[i] = rand() % 256;
    }
}