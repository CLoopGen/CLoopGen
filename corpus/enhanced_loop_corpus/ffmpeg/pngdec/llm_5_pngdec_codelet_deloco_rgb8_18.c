#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int size;
extern int alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < size - 2 && alpha != 0; i += 3 + alpha) {
    int g = dst[i + 1];
    dst[i + 0] += g;
    if (dst[i + 2] < 255) {
        dst[i + 2] += g;
    }
}
}
