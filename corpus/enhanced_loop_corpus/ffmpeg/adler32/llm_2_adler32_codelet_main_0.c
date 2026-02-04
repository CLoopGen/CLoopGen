#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t data[7001];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 4th element first, then proceed with stride)
    for (i = 0; i < 7001; i += 4) {
        if (i < 7001) data[i] = ((i * i) >> 3) + 123 * i;
        if (i + 1 < 7001) data[i + 1] = (((i + 1) * (i + 1)) >> 3) + 123 * (i + 1);
        if (i + 2 < 7001) data[i + 2] = (((i + 2) * (i + 2)) >> 3) + 123 * (i + 2);
        if (i + 3 < 7001) data[i + 3] = (((i + 3) * (i + 3)) >> 3) + 123 * (i + 3);
    }
}
