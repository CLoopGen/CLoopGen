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
    int idx = 0;
    int total = w * h;
    for (idx = 0; idx < total; idx++) {
        int y = idx / w;
        int x = idx % w;
        int s_index = x + y * stride;
        int b_index = x + w * y;
        int v = src[s_index] - ref[s_index];
        block[0][b_index] = v;
        best_score += v * v;
        block_sum[0] += v;
    }
}
