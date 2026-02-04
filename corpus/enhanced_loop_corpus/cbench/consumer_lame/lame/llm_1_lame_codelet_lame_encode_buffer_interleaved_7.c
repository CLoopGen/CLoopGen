#include <stdio.h>

#include <inttypes.h>

extern short buffer[];
extern int nsamples;
extern int i;
extern short *buffer_l;
extern short *buffer_r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nsamples; i += 2) {
    if (i < nsamples) {
        buffer_l[i] = buffer[2 * i];
        buffer_r[i] = buffer[2 * i + 1];
    }
    if (i + 1 < nsamples) {
        buffer_l[i + 1] = buffer[2 * (i + 1)];
        buffer_r[i + 1] = buffer[2 * (i + 1) + 1];
    }
}
}
