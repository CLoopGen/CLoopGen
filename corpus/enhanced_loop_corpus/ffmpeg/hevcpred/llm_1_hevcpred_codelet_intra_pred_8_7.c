#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern ptrdiff_t stride;
extern uint8_t *src;
extern uint8_t *left;
extern int bottom_left_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (bottom_left_size > 0) {
        i = size;
        for (int extra_loop = 0; extra_loop < 1; extra_loop++) {
            for (; i < size + bottom_left_size; i++) {
                left[i] = src[(-1) + stride * (i)];
            }
        }
    }
}
