#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp;
    for (i = 0; i < width; i++) {
        temp = (dst[i] * 14071 + 33561947) >> 14;
        dst[i] = temp;
    }
}
