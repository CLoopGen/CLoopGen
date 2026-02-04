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
    for (int i = 0; i < bins; i++) {
        for (int k = 0; k < 1; k++) {
            dst[i] += f * src[i];
        }
    }
}
