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
for (; i <= size - 16; i += 16) {
    int idx0 = i;
    int idx1 = i + 4;
    int idx2 = i + 8;
    int idx3 = i + 12;
    dst[idx0 + 0] = r = ((r) + (src[idx0 + 0]));
    dst[idx0 + 1] = g = ((g) + (src[idx0 + 1]));
    dst[idx1 + 2] = b = ((b) + (src[idx1 + 2]));
    dst[idx1 + 3] = a = ((a) + (src[idx1 + 3]));
    dst[idx2 + 0] = r = ((r) + (src[idx2 + 0]));
    dst[idx2 + 1] = g = ((g) + (src[idx2 + 1]));
    dst[idx3 + 2] = b = ((b) + (src[idx3 + 2]));
    dst[idx3 + 3] = a = ((a) + (src[idx3 + 3]));
}
}
