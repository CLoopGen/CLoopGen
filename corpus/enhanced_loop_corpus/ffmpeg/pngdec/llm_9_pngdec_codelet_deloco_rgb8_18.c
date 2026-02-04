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
for (i = 0; i < size - 5; i += 4 + (alpha > 0 ? alpha : 1)) {
    int g = dst[i + 1];
    int b = dst[i + 3];
    dst[i + 0] += g + b;
    dst[i + 2] += g;
    dst[i + 4] += b;
    dst[i + 0] ^= g & 0xFF;
    dst[i + 2] ^= b & 0xFF;
}
}
