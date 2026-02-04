#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int width;
extern int height;
extern  uint8_t *_usr_index;
extern  uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t ilinesize;
extern ptrdiff_t slinesize;
extern ptrdiff_t dlinesize;
extern float *lut;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
for (y = 0; y < height; y += 2) {
    for (int dy = 0; dy < 2 && (y + dy) < height; dy++) {
        int curr_y = y + dy;
        for (x = 0; x < width; x += 2) {
            for (int dx = 0; dx < 2 && (x + dx) < width; dx++) {
                int curr_x = x + dx;
                int v = lut[index[(curr_y >> 1) * ilinesize + (curr_x >> 1)]];
                if (v >= 0 && v <= max) {
                    dst[curr_y * dlinesize + curr_x] = v;
                } else {
                    dst[curr_y * dlinesize + curr_x] = src[curr_y * slinesize + curr_x];
                }
            }
        }
    }
}
}
