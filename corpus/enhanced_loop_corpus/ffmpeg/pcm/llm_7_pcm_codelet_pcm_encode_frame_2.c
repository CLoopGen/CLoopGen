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
    short *s = samples;
    unsigned char *d = dst;
    for (int i = 0; i < n; i++) {
        int val = s[i];
        d[i] = linear_to_ulaw[(val + 32768) >> 2];
    }
    samples += n;
    dst += n;
    n = 0;
}
