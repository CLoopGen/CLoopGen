#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct YuvPixel {
    int8_t y;
    int8_t v;
    int8_t u;
} YuvPixel;

extern YuvPixel *p;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing adjacent elements, we access every second element in a strided manner.
    // This changes the memory access pattern to skip elements, simulating strided behavior.
    for (i = 0; i < 31; i += 2) {  // Outer loop step changed to 2 (strided)
        for (j = 31; j > i; j -= 2) {
            if (!(p[j].u | p[j].v | p[j].y))
                p[j] = p[j - 2];  // Stride of 2 in backward copy
        }
        for (j = 0; j < 31 - i; j += 2) {
            if (!(p[j].u | p[j].v | p[j].y))
                p[j] = p[j + 2];  // Stride of 2 in forward copy
        }
    }
}
