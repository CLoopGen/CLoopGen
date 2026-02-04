#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern uint8_t mask;
extern uint8_t color;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i += 2) {
        int shift1 = 7 - i;
        int shift2 = 3 - (i >> 1);
        if (mask & (1 << shift1))
            dst[i >> 1] = color;
        if (i < 4 && (mask & (1 << shift2)))
            dst[width + (i >> 1)] = color;
    }
}
