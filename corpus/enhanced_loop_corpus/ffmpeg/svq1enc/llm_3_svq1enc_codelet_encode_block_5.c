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
for (x = 0; x < w; x++) {
    for (y = 0; y < h; y++) {
        int src_idx = x + y * stride;
        int ref_idx = x + y * stride;
        int block_idx = x + y * w;
        int v = src[src_idx] - ref[ref_idx];
        block[0][block_idx] = v;
        best_score += v * v;
        block_sum[0] += v;
    }
}
}
