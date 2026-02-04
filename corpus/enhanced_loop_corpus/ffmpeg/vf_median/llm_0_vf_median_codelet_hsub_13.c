#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern int bins;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < bins; j += 2) {
        if (j + 1 < bins) {
            dst[j] -= src[j];
            dst[j+1] -= src[j+1];
        } else {
            dst[j] -= src[j];
        }
    }
}
