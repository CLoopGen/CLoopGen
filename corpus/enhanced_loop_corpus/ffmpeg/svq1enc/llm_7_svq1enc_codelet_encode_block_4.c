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
    int local_block_sum = block_sum[0];
    int local_best_score = best_score;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            int v = src[x + y * stride];
            block[0][x + w * y] = v;
            local_best_score += v * v;
            local_block_sum += v;
        }
    }
    best_score = local_best_score;
    block_sum[0] = local_block_sum;
}
