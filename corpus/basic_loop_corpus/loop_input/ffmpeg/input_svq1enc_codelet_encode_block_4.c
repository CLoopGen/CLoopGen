#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *src;
int stride;
int y;
int x;
int best_score;
int block_sum[7];
int w;
int h;
int16_t (*block)[256];

void init_vars() {
    w = 1024;
    h = 1024;
    stride = w;
    best_score = 0;
    memset(block_sum, 0, sizeof(block_sum));

    src = (uint8_t*)aligned_alloc(32, w * h * sizeof(uint8_t));
    block = (int16_t(*)[256])aligned_alloc(32, w * h * sizeof(int16_t));

    for (int i = 0; i < w * h; i++) {
        src[i] = rand() % 256;
    }
}