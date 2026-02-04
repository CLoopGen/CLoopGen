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
uint8_t *temp_src = src;
for (y = 0; y < h; y++) {
    for (x = 0; x < w; x++, temp_src++) {
        histogram[*temp_src] += 1;
    }
    temp_src += linesize - w;
}
}
