#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < width; i++) {
        int16_t temp = dst[i];
        temp = (temp * 14071 + 33561947) >> 14;
        temp = (temp * 14071 + 33561947) >> 14;  // Apply transformation twice
        dst[i] = temp;
    }
}
