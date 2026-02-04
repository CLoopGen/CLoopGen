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
    for (; n > 0; n--) {
        v = *samples++;
        if (v >= -32768 && v <= 32767) {
            *dst++ = linear_to_ulaw[(v + 32768) >> 2];
        } else {
            *dst++ = 0xFF; // Clamp to default u-law value for out-of-range
        }
    }
}
