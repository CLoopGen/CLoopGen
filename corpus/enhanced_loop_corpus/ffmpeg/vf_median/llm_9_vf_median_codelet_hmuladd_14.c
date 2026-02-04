#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern int f;
extern int bins;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < bins; i++) {
        dst[i] += f * (src[i] + src[i] * 2);
        dst[i] += f * (src[i] >> 1);
    }
}
