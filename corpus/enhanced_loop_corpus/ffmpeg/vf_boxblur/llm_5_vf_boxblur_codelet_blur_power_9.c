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
    for (i = 0; i < len; i++) {
        uint16_t val = ((uint16_t *)a)[i];
        if (val % 2 == 0) {
            *(uint16_t *)(dst + i * dst_step) = val;
        } else {
            *(uint16_t *)(dst + i * dst_step) = val + 1;
        }
    }
}
