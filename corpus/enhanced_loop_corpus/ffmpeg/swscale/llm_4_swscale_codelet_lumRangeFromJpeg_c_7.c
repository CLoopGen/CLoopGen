#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (width <= 0) return;
    for (i = 0; i < width; i++) {
        int16_t val = dst[i];
        if (val == 0) continue;
        dst[i] = (val * 14071 + 33561947) >> 14;
    }
}
