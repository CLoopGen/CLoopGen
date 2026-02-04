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
    for (y = 0; y < 8; y++) {
        const uint8_t *cm_in = cm + src[-1];
        // Change to consecutive memory access via pointer arithmetic on top and src
        uint8_t *s = src;
        const uint8_t *t = top;
        s[0] = cm_in[t[0]];
        s[1] = cm_in[t[1]];
        s[2] = cm_in[t[2]];
        s[3] = cm_in[t[3]];
        s[4] = cm_in[t[4]];
        s[5] = cm_in[t[5]];
        s[6] = cm_in[t[6]];
        s[7] = cm_in[t[7]];
        src += stride;
    }
}
