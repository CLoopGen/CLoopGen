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
for (i = 0; i < size - 4; i += 2 + alpha) {
    int g = dst[i + 1];
    dst[i + 0] += g;
    dst[i + 2] += g;
    dst[i + 3] += g;
    dst[i + 0] -= g >> 1;
}
}
