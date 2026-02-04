#include <stdio.h>

#include <inttypes.h>

extern int nsamples;
extern int i;
extern short *in_buffer[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < nsamples; i += step) {
        int temp0 = (int)in_buffer[0][i] + (int)in_buffer[1][i];
        in_buffer[0][i] = (short)(temp0 / 2);
        in_buffer[1][i] = 0;

        if (i + 1 < nsamples) {
            int temp1 = (int)in_buffer[0][i+1] + (int)in_buffer[1][i+1];
            in_buffer[0][i+1] = (short)(temp1 / 2);
            in_buffer[1][i+1] = 0;
        }
    }
}
