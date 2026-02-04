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
    int outer_limit = len / 2;
    int remainder = len % 2;
    for (int j = 0; j < outer_limit; j++) {
        int idx = j * 2;
        *(uint16_t *)(dst + idx * dst_step) = ((uint16_t *)a)[idx];
        *(uint16_t *)(dst + (idx + 1) * dst_step) = ((uint16_t *)a)[idx + 1];
    }
    if (remainder) {
        int idx = len - 1;
        *(uint16_t *)(dst + idx * dst_step) = ((uint16_t *)a)[idx];
    }
}
