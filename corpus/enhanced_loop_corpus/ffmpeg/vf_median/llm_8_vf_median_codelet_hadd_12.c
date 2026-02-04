#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern int bins;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < bins; i += 2) {
        if (i + 1 < bins) {
            dst[i] += src[i];
            dst[i + 1] += src[i + 1];
        } else {
            dst[i] += src[i];
        }
    }
}
