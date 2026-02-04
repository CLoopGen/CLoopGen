#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (width + 3) / 4;
    for (i = 0; i < limit; i++) {
        int base = i * 4;
        if (base < width) dst[base] = (dst[base] * 14071 + 33561947) >> 14;
        if (base + 1 < width) dst[base + 1] = (dst[base + 1] * 14071 + 33561947) >> 14;
        if (base + 2 < width) dst[base + 2] = (dst[base + 2] * 14071 + 33561947) >> 14;
        if (base + 3 < width) dst[base + 3] = (dst[base + 3] * 14071 + 33561947) >> 14;
    }
}
