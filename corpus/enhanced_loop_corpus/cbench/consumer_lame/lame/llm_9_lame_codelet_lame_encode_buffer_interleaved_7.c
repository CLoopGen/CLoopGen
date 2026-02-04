#include <stdio.h>

#include <inttypes.h>

extern short buffer[];
extern int nsamples;
extern int i;
extern short *buffer_l;
extern short *buffer_r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx_l, idx_r;
    for (i = 0; i < nsamples; i++) {
        idx_l = i << 1;
        idx_r = idx_l + 1;
        buffer_l[i] = buffer[idx_l];
        buffer_r[i] = buffer[idx_r];
    }
}
