#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t magnitude;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — write every second element first, then fill gaps (stride of 2)
    int stride = 2;
    // First pass: strided access with step size 2
    for (i = 0; i < width; i += stride) {
        bits[i] = (magnitude >> (width - i - 1)) & 1 ? '1' : '0';
    }
    // Second pass: fill in the skipped indices
    for (i = 1; i < width; i += stride) {
        bits[i] = (magnitude >> (width - i - 1)) & 1 ? '1' : '0';
    }
}
