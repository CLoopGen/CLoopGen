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
    for (i = 0; i < lap; i += 2) {
        rb_dst[i] |= rb_src[i];
        if (i + 1 < lap)
            rb_dst[i + 1] |= rb_src[i + 1];
    }
}
