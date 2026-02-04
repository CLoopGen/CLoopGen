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
    for (i = 0; i < 8; i++) {
        int offset = (i < 4) ? 0 : width;
        int idx = i < 4 ? i : i - 4;
        if (mask & (1 << (i < 4 ? 7 - idx : 3 - idx)))
            dst[offset + idx] = src[offset + idx];
    }
}
