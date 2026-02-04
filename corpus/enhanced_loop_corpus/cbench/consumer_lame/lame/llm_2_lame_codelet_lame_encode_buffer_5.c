#include <stdio.h>

#include <inttypes.h>

extern int nsamples;
extern int i;
extern short *in_buffer[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (stride of 2)
    for (i = 0; i < nsamples; i += 2) {
        if (i + 1 < nsamples) {
            in_buffer[0][i] = ((int)in_buffer[0][i] + (int)in_buffer[1][i]) / 2;
            in_buffer[0][i + 1] = ((int)in_buffer[0][i + 1] + (int)in_buffer[1][i + 1]) / 2;
            in_buffer[1][i] = 0;
            in_buffer[1][i + 1] = 0;
        } else {
            in_buffer[0][i] = ((int)in_buffer[0][i] + (int)in_buffer[1][i]) / 2;
            in_buffer[1][i] = 0;
        }
    }
}
