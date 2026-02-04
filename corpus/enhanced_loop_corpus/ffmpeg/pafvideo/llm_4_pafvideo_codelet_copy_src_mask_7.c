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
    for (i = 0; i < 4; i++) {
        uint8_t shift1 = 7 - i;
        uint8_t shift2 = 3 - i;
        if ((mask & (1 << shift1)) && (mask & (1 << shift2))) {
            dst[i] = src[i];
            dst[width + i] = src[width + i];
        } else if (mask & (1 << shift1)) {
            dst[i] = src[i];
        } else if (mask & (1 << shift2)) {
            dst[width + i] = src[width + i];
        }
    }
}
