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
    int idx;
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            idx = x + y * stride;
            decoded[idx] = src[idx] - block[best_count][x + w * y] + best_mean;
        }
    }
}
