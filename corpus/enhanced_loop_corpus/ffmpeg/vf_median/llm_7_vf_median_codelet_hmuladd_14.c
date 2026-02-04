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
    uint16_t local_f = f;
    for (int i = 0; i < bins; i++) {
        uint16_t product = local_f * src[i];
        dst[i] = product;
    }
    for (int i = 1; i < bins; i++) {
        dst[i] += dst[i-1];
    }
}
