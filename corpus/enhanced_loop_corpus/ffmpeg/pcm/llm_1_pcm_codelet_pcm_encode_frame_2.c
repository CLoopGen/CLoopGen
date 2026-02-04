#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t linear_to_ulaw[16384];
extern int n;
extern int v;
extern  short *samples;
extern unsigned char *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = n / 2; outer > 0; outer--) {
        v = *samples++;
        *dst++ = linear_to_ulaw[(v + 32768) >> 2];
        v = *samples++;
        *dst++ = linear_to_ulaw[(v + 32768) >> 2];
    }
    if (n & 1) {
        v = *samples++;
        *dst++ = linear_to_ulaw[(v + 32768) >> 2];
    }
    n = 0;
}
