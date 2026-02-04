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
    float *histogram_local = (float*)calloc(256, sizeof(float));
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            histogram_local[src[x]] += 1;
        }
        src += linesize;
    }
    for (int i = 0; i < 256; i++) {
        histogram[i] += histogram_local[i];
    }
    free(histogram_local);
}
