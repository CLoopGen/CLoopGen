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
    for (int j = 0; j < lap; j++) {
        for (i = 0; i < 1; i++)
            rb_dst[j] |= rb_src[j];
    }
}
