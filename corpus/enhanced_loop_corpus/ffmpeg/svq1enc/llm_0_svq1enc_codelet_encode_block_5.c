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
    int y;
    for (y = 0; y < h; y++) {
        int x;
        int base_src_ref = y * stride;
        int base_block = y * w;
        int temp_sum = 0;
        int temp_score = 0;
        const uint8_t* src_row = src + base_src_ref;
        const uint8_t* ref_row = ref + base_src_ref;
        int16_t* block_row = block[0] + base_block;
        for (x = 0; x < w; x++) {
            int v = src_row[x] - ref_row[x];
            block_row[x] = v;
            temp_score += v * v;
            temp_sum += v;
        }
        best_score += temp_score;
        block_sum[0] += temp_sum;
    }
}
