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
    for (i = 0; i < nsamples * 2; i += 2) {
        j = i >> 1;
        buffer_l[j] = buffer[i];
        buffer_r[j] = buffer[i + 1];
    }
}
