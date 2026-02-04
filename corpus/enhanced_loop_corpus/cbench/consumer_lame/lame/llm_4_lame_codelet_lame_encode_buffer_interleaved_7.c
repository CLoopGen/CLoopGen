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
        if (i % 2 == 0) {
            buffer_l[i/2] = buffer[2 * (i/2)];
        } else {
            buffer_r[i/2] = buffer[2 * (i/2) + 1];
        }
    }
}
