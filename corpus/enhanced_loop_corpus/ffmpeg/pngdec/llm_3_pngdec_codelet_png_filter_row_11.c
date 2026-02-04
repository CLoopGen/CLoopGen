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
    // Variant 2: Strided memory access with stride of 8 (process every 8th byte, unrolled by 4)
    int stride = 8;
    for (; i <= size - 4 * stride; i += 4 * stride) {
        dst[i + 0 * stride] = r = ((r) + (src[i + 0 * stride]));
        if (4 == 1)
            continue;
        dst[i + 1 * stride] = g = ((g) + (src[i + 1 * stride]));
        if (4 == 2)
            continue;
        dst[i + 2 * stride] = b = ((b) + (src[i + 2 * stride]));
        if (4 == 3)
            continue;
        dst[i + 3 * stride] = a = ((a) + (src[i + 3 * stride]));
    }
}
