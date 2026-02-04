#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int lap;
extern uint8_t *rb_src;
extern uint8_t *rb_dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_index;
    for (i = 1; i <= lap; i++) {
        prev_index = i - 1;
        if (prev_index >= 0)
            rb_dst[prev_index] |= rb_src[i-1];
    }
}
