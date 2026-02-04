#include <stdio.h>

#include <inttypes.h>

extern int nsamples;
extern int i;
extern short *in_buffer[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse Consecutive Memory Access (process array from end to start)
    for (i = nsamples - 1; i >= 0; --i) {
        in_buffer[0][i] = ((int)in_buffer[0][i] + (int)in_buffer[1][i]) / 2;
        in_buffer[1][i] = 0;
    }
}
