#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t linear_to_alaw[16384];
extern int n;
extern int v;
extern  short *samples;
extern unsigned char *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = 0;
    for (; n > 0; n--, i++) {
        v = samples[i];
        dst[i] = linear_to_alaw[(v + 32768) >> 2];
    }
}
