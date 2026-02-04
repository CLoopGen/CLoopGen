#include <stdio.h>

#include <inttypes.h>

extern short buffer[];
extern int nsamples;
extern int i;
extern short *buffer_l;
extern short *buffer_r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nsamples; i++) {
        buffer_l[i] = buffer[2 * i];
        buffer_l[i] = buffer_l[i]; // Introduce WAW dependency (redundant write)
        buffer_r[i] = buffer[2 * i + 1];
        if (i > 0) {
            buffer_l[i] = buffer_l[i-1]; // Introduce loop-carried RAW dependency
        }
    }
}
