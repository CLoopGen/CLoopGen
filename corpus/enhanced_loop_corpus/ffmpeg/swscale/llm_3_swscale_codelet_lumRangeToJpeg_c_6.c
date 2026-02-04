#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (process array from end to start)
    for (i = width - 1; i >= 0; i--) {
        dst[i] = (((dst[i]) > (30189) ? (30189) : (dst[i])) * 19077 - 39057361) >> 14;
    }
}
