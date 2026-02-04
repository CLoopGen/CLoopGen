#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t nops[10000];
extern int i;
extern uint64_t t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 4th element first, then next stride)
    for (i = 0; i < 10000; i += 4) {
        if (i + 0 < 10000) nops[i + 0] = t;
        if (i + 1 < 10000) nops[i + 1] = t;
        if (i + 2 < 10000) nops[i + 2] = t;
        if (i + 3 < 10000) nops[i + 3] = t;
    }
}
