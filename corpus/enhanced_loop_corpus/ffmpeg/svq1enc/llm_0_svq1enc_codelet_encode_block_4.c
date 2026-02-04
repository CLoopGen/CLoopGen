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
    int row_sum = 0;
    int row_score = 0;
    for (x = 0; x < w; x++) {
        int v = src[x + y * stride];
        block[0][x + w * y] = v;
        row_score += v * v;
        row_sum += v;
    }
    best_score += row_score;
    block_sum[0] += row_sum;
}
}
