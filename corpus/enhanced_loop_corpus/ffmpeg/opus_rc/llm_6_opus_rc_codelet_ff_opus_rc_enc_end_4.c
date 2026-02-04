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
    int j;
    uint8_t temp = 0;
    for (i = 0; i < lap; i++) {
        temp = rb_src[i];
        rb_dst[i] |= temp;
    }
}
