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
    int step = 4;
    for (; i <= size - step; i += step) {
        dst[i + 0] = r = ((r) + (src[i + 0]));
        dst[i + 1] = g = ((g) + (src[i + 1]));
        dst[i + 2] = b = ((b) + (src[i + 2]));
        dst[i + 3] = a = ((a) + (src[i + 3]));
    }
    // Handle remaining elements if size is not multiple of 4
    for (; i <= size - 1; i += 1) {
        dst[i] = r = ((r) + (src[i]));
    }
}
