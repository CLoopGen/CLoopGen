#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height * width; i++) {
    int j = i % width;
    int row_start = (i / width) * stride;
    ((uint8_t*)(dst + row_start))[j] = 
        (((uint8_t*)(dst + row_start))[j] + 
         (((3 * ((uint8_t*)(src + row_start))[j] + 
            4 * ((uint8_t*)(src + row_start))[j + 1] + 
            2 * ((uint8_t*)(src + row_start))[j + stride] + 
            3 * ((uint8_t*)(src + row_start))[j + stride + 1] + 6) * 2731) >> 15) + 1) >> 1;
}
}
