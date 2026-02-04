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
        if (i > 0)
            *(uint16_t *)(dst + (i-1) * dst_step) = ((uint16_t *)a)[i]; // Introduce WAW and WAR dependency: write before prior write, read current element to write previous
        if (i == len - 1)
            *(uint16_t *)(dst + i * dst_step) = ((uint16_t *)a)[i];
    }
    if (len == 0) return;
}
