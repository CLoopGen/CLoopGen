#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (i = width - 1; i >= 0; i--) {
        dst[i] = (dst[i] * 14071 + 33561947) >> 14;
    }
}
