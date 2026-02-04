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
for (i = 0; i < size - 2 && alpha != 0; i += 3 + alpha) {
    int g = dst[i + 1];
    if (g % 2 == 0) {
        dst[i + 0] += g;
    } else {
        dst[i + 2] += g;
    }
}
}
