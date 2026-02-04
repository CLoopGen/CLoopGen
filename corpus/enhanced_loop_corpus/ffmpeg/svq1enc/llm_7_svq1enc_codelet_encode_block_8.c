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
    int i, j, temp_val;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            temp_val = block[best_count][j + w * i];
            decoded[j + i * stride] = src[j + i * stride] - temp_val + best_mean;
        }
    }
}
