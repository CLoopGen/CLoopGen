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
    for (i = 0; i < bins; i += 2) {
        if (i + 1 < bins) {
            dst[i] += f * src[i];
            dst[i+1] += f * src[i+1];
        } else {
            dst[i] += f * src[i];
        }
    }
}
