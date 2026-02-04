#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *src;
uint8_t *decoded;
int stride;
int y;
int x;
int best_mean;
int best_count;
int w;
int h;
int16_t (*block)[256];

void init_vars() {
    w = 512;
    h = 512;
    stride = w;
    best_mean = 128;
    best_count = 0;

    src = (uint8_t*)aligned_alloc(32, stride * h * sizeof(uint8_t));
    decoded = (uint8_t*)aligned_alloc(32, stride * h * sizeof(uint8_t));

    block = (int16_t(*)[256])aligned_alloc(32, sizeof(int16_t) * 256 * 256);
    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            block[i][j] = rand() % 256 - 128;
        }
    }

    for (int i = 0; i < stride * h; i++) {
        src[i] = rand() % 256;
        decoded[i] = 0;
    }
}