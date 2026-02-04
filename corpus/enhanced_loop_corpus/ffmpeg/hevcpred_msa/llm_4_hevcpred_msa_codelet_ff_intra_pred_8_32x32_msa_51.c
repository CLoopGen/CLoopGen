#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern ptrdiff_t stride;
extern uint8_t *src;
extern uint8_t *left;
extern int bottom_left_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 32; i < 32 + bottom_left_size; i++) {
        if (i >= 0) {
            left[i] = src[-1 + stride * i];
        }
    }
}
