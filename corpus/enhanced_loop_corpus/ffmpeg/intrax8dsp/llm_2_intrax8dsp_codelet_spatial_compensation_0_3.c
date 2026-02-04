#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t zero_prediction_weights[128];
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;
extern uint16_t left_sum[2][8];
extern uint16_t top_sum[2][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access via flattened indexing with precomputed weights and sums
    uint32_t temp[64];
    uint16_t *w = zero_prediction_weights;
    uint16_t *ts = left_sum[0];
    uint16_t *ls = top_sum[0];

    for (int i = 0; i < 64; i++) {
        int y = i >> 3;
        int x = i & 7;
        temp[i] = ((uint32_t)ls[x] * w[y * 16 + x * 2 + 0] + 
                   (uint32_t)ts[y] * w[y * 16 + x * 2 + 1] + 32768) >> 16;
    }

    uint8_t *d = dst;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            d[j] = temp[i * 8 + j];
        }
        d += stride;
    }
}
