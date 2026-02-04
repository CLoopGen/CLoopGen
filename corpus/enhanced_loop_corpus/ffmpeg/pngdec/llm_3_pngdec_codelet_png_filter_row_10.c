#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int size;
extern int i;
extern int r;
extern int g;
extern int b;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride (every 4th element)
    // Modify access pattern to use a fixed stride of 4 instead of incrementing by 3
    // This changes spatial locality and simulates processing of interleaved data (e.g., RGBA skipping every other pixel)
    int stride = 4;
    for (; i <= size - stride; i += stride) {
        dst[i + 0] = r = (r + src[i + 0]);
        if (stride >= 2)
            dst[i + 1] = g = (g + src[i + 1]);
        if (stride >= 3)
            dst[i + 2] = b = (b + src[i + 2]);
        if (stride >= 4)
            dst[i + 3] = a = (a + src[i + 3]);
    }
}
