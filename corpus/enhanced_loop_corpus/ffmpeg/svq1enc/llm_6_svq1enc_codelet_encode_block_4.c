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
    int temp_sum = 0;
    int temp_score = 0;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            int idx = x + y * stride;
            int v = src[idx];
            block[0][x + w * y] = v;
            temp_score += v * v;
            temp_sum += v;
        }
    }
    best_score += temp_score;
    block_sum[0] += temp_sum;
}
