#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *speech;
extern int subframe_size;
extern int temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int scale_factor = 8192;
    for (i = 0; i < subframe_size; i++) {
        int16_t val = speech[i];
        int product = val * temp;
        int biased = product + scale_factor;
        int shifted = biased >> 14;
        speech[i] = (int16_t)shifted;
    }
}
