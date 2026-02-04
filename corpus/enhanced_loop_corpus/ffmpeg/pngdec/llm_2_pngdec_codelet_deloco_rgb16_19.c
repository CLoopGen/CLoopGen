#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern int size;
extern int alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < size - 2; i += 3 + alpha) {
    int g = dst[i];
    dst[i + 1] += g;
    dst[i + 2] += g;
}
}
