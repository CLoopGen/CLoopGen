#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern ptrdiff_t stride;
extern uint8_t *src;
extern uint8_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    left[0] = src[-1];
    for (i = 1; i < 16; i++) {
        left[i] = src[-1 + stride * i] + (left[i-1] & 0x0F);
    }
}
