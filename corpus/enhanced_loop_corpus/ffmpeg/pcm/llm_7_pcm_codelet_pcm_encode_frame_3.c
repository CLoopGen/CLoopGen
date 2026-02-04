#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t linear_to_vidc[16384];
extern int n;
extern int v;
extern  short *samples;
extern unsigned char *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_dst = dst;
    short *local_samples = samples;
    int i;
    for (i = 0; i < n; i++) {
        int index = (local_samples[i] + 32768) >> 2;
        local_dst[i] = linear_to_vidc[index];
    }
    dst += n;
    samples += n;
    n = 0;
}
