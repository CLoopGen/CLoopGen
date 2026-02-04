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
    for (y = 0; y < h; y++) {
        float temp_sum = 0.0f;
        for (x = 0; x < w; x++) {
            uint16_t index = src[x];
            temp_sum += 1.0f;
            histogram[index] += temp_sum; 
            temp_sum = histogram[index]; 
        }
        src += linesize;
    }
}
