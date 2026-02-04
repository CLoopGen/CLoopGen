#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern ptrdiff_t stride;
extern uint16_t *src;
extern uint16_t *left;
extern int bottom_left_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (size < size + bottom_left_size) {
        i = size;
        for (; i < size + bottom_left_size; i++) {
            left[i] = src[(-1) + stride * (i)];
        }
    }
}
