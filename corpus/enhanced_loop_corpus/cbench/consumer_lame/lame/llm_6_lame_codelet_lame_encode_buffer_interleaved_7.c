#include <stdio.h>

#include <inttypes.h>

extern short buffer[];
extern int nsamples;
extern int i;
extern short *buffer_l;
extern short *buffer_r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    short temp_l, temp_r;
    for (i = 0; i < nsamples; i++) {
        temp_l = buffer[2 * i];
        temp_r = buffer[2 * i + 1];
        buffer_l[i] = temp_l;
        buffer_r[i] = temp_r;
    }
}
