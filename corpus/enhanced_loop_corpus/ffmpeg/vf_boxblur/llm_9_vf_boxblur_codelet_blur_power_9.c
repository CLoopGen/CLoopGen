#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int dst_step;
extern int len;
extern uint8_t *a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len * 2; i += 2) {
        uint16_t val = ((uint16_t *)a)[i >> 1];
        *(uint16_t *)(dst + (i >> 1) * dst_step) = val;
    }
}
