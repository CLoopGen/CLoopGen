#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern int bins;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < bins * 2; i++) {
        int idx = i / 2;
        if (idx < bins) {
            dst[idx] -= src[idx];
        }
    }
}
