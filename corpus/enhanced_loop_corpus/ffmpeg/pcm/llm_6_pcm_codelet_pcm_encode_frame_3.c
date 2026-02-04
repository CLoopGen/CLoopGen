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
    int temp = 0;
    for (; n > 0; n--) {
        v = *samples++;
        temp = (v + 32768) >> 2;
        *dst++ = linear_to_vidc[temp];
    }
}
