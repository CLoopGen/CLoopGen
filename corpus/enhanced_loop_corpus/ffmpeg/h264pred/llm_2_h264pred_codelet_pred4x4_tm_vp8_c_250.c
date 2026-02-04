#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern  uint8_t *cm;
extern uint8_t *top;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 4; y++) {
        const uint8_t *cm_in = cm + src[-1];
        // Change memory access pattern to consecutive write via pointer arithmetic unrolling
        uint8_t *s = src;
        s[0] = cm_in[top[0]];
        s[1] = cm_in[top[1]];
        s[2] = cm_in[top[2]];
        s[3] = cm_in[top[3]];
        src += stride;
    }
}
