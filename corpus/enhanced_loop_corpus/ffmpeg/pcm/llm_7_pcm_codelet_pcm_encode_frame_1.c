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
    short temp_v;
    uint8_t temp_result;
    for (; n > 0; n--) {
        temp_v = *samples++;
        temp_result = linear_to_alaw[(temp_v + 32768) >> 2];
        *dst++ = temp_result;
    }
}
