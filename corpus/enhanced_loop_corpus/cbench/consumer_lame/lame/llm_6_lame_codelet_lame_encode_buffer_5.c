#include <stdio.h>

#include <inttypes.h>

extern int nsamples;
extern int i;
extern short *in_buffer[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp;
    for (i = 0; i < nsamples; ++i) {
        temp = ((int)in_buffer[0][i] + (int)in_buffer[1][i]) / 2;
        in_buffer[0][i] = temp;
        in_buffer[1][i] = 0;
    }
}
