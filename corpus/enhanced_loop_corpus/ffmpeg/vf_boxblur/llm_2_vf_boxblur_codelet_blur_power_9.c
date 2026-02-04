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
    for (j = 0; j < len; j++) {
        size_t idx = j;
        *(uint16_t *)(dst + idx * dst_step) = ((uint16_t *)a)[idx];
    }
}
