#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out;
extern int i;
extern int stride;
extern int map;
extern int hi;
extern int lo;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 4; i++) {
    for (j = 0; j < 1; j++) { // Increased loop depth: added inner loop with fixed iteration
        if (map & 1)
            out[0] = hi;
        else
            out[0] = lo;
        if (map & 2)
            out[1] = hi;
        else
            out[1] = lo;
        if (map & 4)
            out[2] = hi;
        else
            out[2] = lo;
        if (map & 8)
            out[3] = hi;
        else
            out[3] = lo;
        map >>= 4;
        out += stride;
    }
}
}
