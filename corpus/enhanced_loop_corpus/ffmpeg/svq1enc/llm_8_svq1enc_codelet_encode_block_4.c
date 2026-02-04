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
for (y = 0; y < h; y++) {
    int offset = y * stride;
    for (x = 0; x < w; x += 4) {
        int idx1 = x + offset;
        int idx2 = x + 1 + offset;
        int idx3 = x + 2 + offset;
        int idx4 = x + 3 + offset;
        
        int v1 = src[idx1];
        int v2 = src[idx2];
        int v3 = src[idx3];
        int v4 = src[idx4];

        block[0][x + w * y] = v1;
        block[0][x + 1 + w * y] = v2;
        block[0][x + 2 + w * y] = v3;
        block[0][x + 3 + w * y] = v4;

        best_score += v1 * v1 + v2 * v2 + v3 * v3 + v4 * v4;
        block_sum[0] += v1 + v2 + v3 + v4;
    }
}
}
