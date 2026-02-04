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
    for (x = 0; x < w; x++) {
        if (block[best_count][x + w * y] > best_mean) {
            decoded[x + y * stride] = src[x + y * stride] - block[best_count][x + w * y] + best_mean;
        } else {
            decoded[x + y * stride] = src[x + y * stride];
        }
    }
}
}
