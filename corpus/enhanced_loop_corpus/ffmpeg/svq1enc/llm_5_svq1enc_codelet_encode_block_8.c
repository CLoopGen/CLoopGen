#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *decoded;
extern int stride;
extern int y;
extern int x;
extern int best_mean;
extern int best_count;
extern int w;
extern int h;
extern int16_t (*block)[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < h; y++) {
    int row_offset = y * stride;
    int block_row_offset = y * w;
    for (x = 0; x < w; x++) {
        int16_t block_val = block[best_count][x + block_row_offset];
        uint8_t src_val = src[x + row_offset];
        if (src_val >= block_val) {
            decoded[x + row_offset] = src_val - block_val + best_mean;
        }
    }
}
}
