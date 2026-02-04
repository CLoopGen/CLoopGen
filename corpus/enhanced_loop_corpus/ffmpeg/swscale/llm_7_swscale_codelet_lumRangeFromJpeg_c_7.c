#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (width > 0) {
        dst[0] = (dst[0] * 14071 + 33561947) >> 14;
        for (i = 1; i < width; i++) {
            dst[i] = (dst[i-1] * 14071 + 33561947) >> 14;
        }
    }
}
