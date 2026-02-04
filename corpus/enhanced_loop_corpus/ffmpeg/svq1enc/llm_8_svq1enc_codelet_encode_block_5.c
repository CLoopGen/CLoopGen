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
for (y = 0; y < h; y += 2) {
    for (x = 0; x < w; x += 2) {
        int v1 = src[x + y * stride] - ref[x + y * stride];
        block[0][x + w * y] = v1;
        best_score += v1 * v1;
        block_sum[0] += v1;

        if (x + 1 < w) {
            int v2 = src[(x+1) + y * stride] - ref[(x+1) + y * stride];
            block[0][(x+1) + w * y] = v2;
            best_score += v2 * v2;
            block_sum[0] += v2;
        }

        if (y + 1 < h) {
            int v3 = src[x + (y+1) * stride] - ref[x + (y+1) * stride];
            block[0][x + w * (y+1)] = v3;
            best_score += v3 * v3;
            block_sum[0] += v3;
        }

        if (x + 1 < w && y + 1 < h) {
            int v4 = src[(x+1) + (y+1) * stride] - ref[(x+1) + (y+1) * stride];
            block[0][(x+1) + w * (y+1)] = v4;
            best_score += v4 * v4;
            block_sum[0] += v4;
        }
    }
}
}
