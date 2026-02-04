#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t w;
extern int acc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t outer_i;
    int temp_acc = acc;
    for (outer_i = 0; outer_i < w; outer_i++) {
        temp_acc += src[outer_i];
        dst[outer_i] = temp_acc;
    }
    acc = temp_acc;
}
