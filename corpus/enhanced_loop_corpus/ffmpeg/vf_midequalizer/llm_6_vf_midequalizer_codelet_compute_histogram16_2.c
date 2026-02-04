#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *src;
extern ptrdiff_t linesize;
extern int w;
extern int h;
extern float *histogram;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *histogram_local = (float*)alloca(65536 * sizeof(float));
    for (int i = 0; i < 65536; ++i) {
        histogram_local[i] = 0;
    }
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            uint16_t val = src[x];
            histogram_local[val] += 1;
        }
        src += linesize;
    }
    for (int i = 0; i < 65536; ++i) {
        histogram[i] += histogram_local[i];
    }
}
