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
    int row_offset = y * stride;
    int block_row_offset = y * w;
    for (x = 0; x < w; x++) {
        int src_idx = x + row_offset;
        int ref_idx = x + row_offset;
        int block_idx = x + block_row_offset;
        int v = src[src_idx] - ref[ref_idx];
        block[0][block_idx] = v;
        best_score += v * v;
        block_sum[0] += v;
    }
}
}
