#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int start_x;
extern uint16_t *bufp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (x = 0; x < start_x; x += 2) {
        bufp[x] = bufp[start_x];
    }
}
