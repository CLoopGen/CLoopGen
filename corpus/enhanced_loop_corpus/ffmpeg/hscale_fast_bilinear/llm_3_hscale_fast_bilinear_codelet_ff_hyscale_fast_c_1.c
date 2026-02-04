#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int dstWidth;
extern  uint8_t *src;
extern int srcW;
extern int xInc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — write to every second element in reverse order
    uint8_t pixel_value = src[srcW - 1] * 128;
    for (i = dstWidth - 1; (i * xInc) >> 16 >= srcW - 1; i -= 2) {
        dst[i] = pixel_value;
        if (i > 0) dst[i-1] = pixel_value; // fill stride gap realistically
    }
}
