#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (forward traversal)
    for (i = 0; i < width; i += 2) {
        if (i < width) {
            dst[i] = ((int)(((dst[i]) > (30189 << 4) ? (30189 << 4) : (dst[i])) * 4769U - (39057361 << 2))) >> 12;
        }
    }
    // Handle odd-sized width by processing last element if width is odd
    if (width % 2 == 1) {
        dst[width - 1] = ((int)(((dst[width - 1]) > (30189 << 4) ? (30189 << 4) : (dst[width - 1])) * 4769U - (39057361 << 2))) >> 12;
    }
}
