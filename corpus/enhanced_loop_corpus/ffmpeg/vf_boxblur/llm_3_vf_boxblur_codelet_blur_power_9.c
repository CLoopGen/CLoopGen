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
    for (j = 0; j < len; j += 2) {
        if (j + 1 < len) {
            *(uint16_t *)(dst + (j + 0) * dst_step) = ((uint16_t *)a)[j + 0];
            *(uint16_t *)(dst + (j + 1) * dst_step) = ((uint16_t *)a)[j + 1];
        } else {
            *(uint16_t *)(dst + j * dst_step) = ((uint16_t *)a)[j];
        }
    }
}
