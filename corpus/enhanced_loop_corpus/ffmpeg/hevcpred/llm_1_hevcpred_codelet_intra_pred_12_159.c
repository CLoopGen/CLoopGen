#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int block = 0; block < 7; block++) {
    int start = block * 9;
    int end = (start + 9 < 63) ? start + 9 : 63;
    for (i = start; i < end; i++) {
        left[i] = ((64 - (i + 1)) * left[-1] + (i + 1) * left[63] + 32) >> 6;
    }
}
}
