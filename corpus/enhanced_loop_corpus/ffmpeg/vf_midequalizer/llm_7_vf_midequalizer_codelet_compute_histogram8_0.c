#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern ptrdiff_t linesize;
extern int w;
extern int h;
extern float *histogram;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < h; y++) {
        float temp_hist[256] = {0};
        for (x = 0; x < w; x++) {
            temp_hist[src[x]] += 1;
        }
        src += linesize;
        for (int i = 0; i < 256; i++) {
            histogram[i] += temp_hist[i];
        }
    }
}
