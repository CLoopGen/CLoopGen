#include <stdio.h>

#include <inttypes.h>

extern short buffer[];
extern int nsamples;
extern int i;
extern short *buffer_l;
extern short *buffer_r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < nsamples; j++) {
        int idx = 2 * j;
        buffer_l[j] = buffer[idx];
        buffer_r[j] = buffer[idx + 1];
    }
}
