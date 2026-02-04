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
for (i = 2; i < size; i += 3 + alpha) {
    int g = dst[i - 2];
    dst[i - 1] += g;
    dst[i] += g;
}
}
