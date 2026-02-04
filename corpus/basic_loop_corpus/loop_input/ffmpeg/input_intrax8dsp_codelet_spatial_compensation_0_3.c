#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t zero_prediction_weights[128];

uint8_t *dst;
ptrdiff_t stride;
int x;
int y;

uint16_t left_sum[2][8];
uint16_t top_sum[2][8];

uint8_t *dst_buffer;

void init_vars() {
    for (int i = 0; i < 128; i++) {
        zero_prediction_weights[i] = (uint16_t)(i * i);
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 8; j++) {
            left_sum[i][j] = (uint16_t)(j + 1) * 100;
            top_sum[i][j] = (uint16_t)(j + 1) * 200;
        }
    }

    stride = 16;
    dst_buffer = (uint8_t*)malloc(256 * 1024 * 1024);
    if (!dst_buffer) {
        exit(1);
    }
    dst = dst_buffer;
}