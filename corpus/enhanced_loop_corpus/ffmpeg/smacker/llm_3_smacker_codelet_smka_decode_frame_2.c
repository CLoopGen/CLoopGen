#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *samples;
extern int i;
extern int stereo;
extern int pred[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - write every second element (stride of 2)
    for (i = 0; i <= stereo; i++)
        samples[2 * i] = pred[i];
}
