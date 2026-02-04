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
    int local_n = n >> 1;
    for (; local_n > 0; local_n--) {
        v = *samples++; 
        *dst++ = linear_to_alaw[(v + 32768) >> 3 << 1]; 
        v = *samples++; 
        *dst++ = linear_to_alaw[(v + 32768) >> 3 << 1];
    }
    if (n & 1) {
        v = *samples++;
        *dst++ = linear_to_alaw[(v + 32768) >> 3 << 1];
    }
}
