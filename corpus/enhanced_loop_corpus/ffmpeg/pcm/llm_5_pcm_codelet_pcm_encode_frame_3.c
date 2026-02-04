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
    int i;
    for (i = 0; i < n; i++) {
        if ((v = samples[i], (v + 32768) >> 2) >= 16384) continue;
        dst[i] = linear_to_vidc[(v + 32768) >> 2];
    }
    n = 0;
}
