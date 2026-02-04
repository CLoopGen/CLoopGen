#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern uint8_t mask;
extern  uint8_t *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp1, temp2;
    for (i = 0; i < 4; i++) {
        temp1 = src[i];
        temp2 = src[width + i];
        if (mask & (1 << (7 - i)))
            dst[i] = temp1;
        if (mask & (1 << (3 - i)))
            dst[width + i] = temp2;
    }
}
