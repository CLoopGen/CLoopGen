#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int i;
extern int ff_count;
extern uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 4th element first, then proceed with stride)
    int stride = 4;
    for (int step = 0; step < stride; step++) {
        for (i = step; i < size; i += stride) {
            if (buf[i] == 255)
                ff_count++;
        }
    }
}
