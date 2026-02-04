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
    if (len <= 0) return;
    for (i = 0; i < len; i++) {
        if (((uint16_t *)a)[i] == 0) continue;
        *(uint16_t *)(dst + i * dst_step) = ((uint16_t *)a)[i];
    }
}
