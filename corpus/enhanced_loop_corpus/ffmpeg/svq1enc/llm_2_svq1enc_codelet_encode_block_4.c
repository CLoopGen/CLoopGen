#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern int y;
extern int x;
extern int best_score;
extern int block_sum[7];
extern int w;
extern int h;
extern int16_t (*block)[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by transposing the iteration order
    // We process data column-wise (x-major) to achieve more sequential access in src and block
    for (x = 0; x < w; x++) {
        for (y = 0; y < h; y++) {
            int offset = x + y * stride;
            int v = src[offset];
            block[0][x + w * y] = v;
            best_score += v * v;
            block_sum[0] += v;
        }
    }
}
