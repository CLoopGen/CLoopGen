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
for (y = 0; y < h; y += 2)
    for (x = 0; x < w; x += 2) {
        int offset = x + y * stride;
        int block_offset1 = x + w * y;
        int block_offset2 = (x+1) + w * y;
        int block_offset3 = x + w * (y+1);
        int block_offset4 = (x+1) + w * (y+1);
        decoded[offset] = src[offset] - block[best_count][block_offset1] + best_mean;
        if (x+1 < w) decoded[offset+1] = src[offset+1] - block[best_count][block_offset2] + best_mean;
        if (y+1 < h) decoded[offset+stride] = src[offset+stride] - block[best_count][block_offset3] + best_mean;
        if (x+1 < w && y+1 < h) decoded[offset+stride+1] = src[offset+stride+1] - block[best_count][block_offset4] + best_mean;
    }
}
