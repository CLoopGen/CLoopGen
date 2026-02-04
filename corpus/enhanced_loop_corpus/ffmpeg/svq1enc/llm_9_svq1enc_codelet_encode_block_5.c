#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *ref;
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
for (y = 0; y < h; y++) {
    int offset_y = y * stride;
    int block_offset_y = w * y;
    const int unroll_factor = 4;
    x = 0;
    for (; x <= w - unroll_factor; x += unroll_factor) {
        int v0 = src[x + 0 + offset_y] - ref[x + 0 + offset_y];
        int v1 = src[x + 1 + offset_y] - ref[x + 1 + offset_y];
        int v2 = src[x + 2 + offset_y] - ref[x + 2 + offset_y];
        int v3 = src[x + 3 + offset_y] - ref[x + 3 + offset_y];

        block[0][x + 0 + block_offset_y] = v0;
        block[0][x + 1 + block_offset_y] = v1;
        block[0][x + 2 + block_offset_y] = v2;
        block[0][x + 3 + block_offset_y] = v3;

        best_score += v0*v0 + v1*v1 + v2*v2 + v3*v3;
        block_sum[0] += v0 + v1 + v2 + v3;
    }
    for (; x < w; x++) {
        int v = src[x + y * stride] - ref[x + y * stride];
        block[0][x + w * y] = v;
        best_score += v * v;
        block_sum[0] += v;
    }
}
}
