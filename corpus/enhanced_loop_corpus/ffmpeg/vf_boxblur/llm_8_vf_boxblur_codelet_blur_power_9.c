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
    int j;
    for (i = 0; i < len; i += 2) {
        uint16_t val1 = ((uint16_t *)a)[i];
        *(uint16_t *)(dst + i * dst_step) = val1;
        if (i + 1 < len) {
            uint16_t val2 = ((uint16_t *)a)[i + 1];
            *(uint16_t *)(dst + (i + 1) * dst_step) = val2;
        }
    }
}
