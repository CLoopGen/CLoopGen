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
    // Variant 1: Consecutive memory access by flattening the 2D iteration into a 1D stride-aligned sequential scan
    int index = 0;
    for (y = 0; y < h; y++) {
        int base_src = y * stride;
        int base_block = y * w;
        for (x = 0; x < w; x++) {
            decoded[base_src + x] = src[base_src + x] - block[best_count][base_block + x] + best_mean;
            index++;
        }
    }
}
