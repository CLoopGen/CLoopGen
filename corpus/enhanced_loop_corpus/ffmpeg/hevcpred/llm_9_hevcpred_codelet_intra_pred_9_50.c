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
    int step = 2;
    int limit = size + bottom_left_size - (bottom_left_size % 2);
    for (i = size; i < limit; i += step) {
        left[i] = src[(-1) + stride * i];
        left[i + 1] = src[(-1) + stride * (i + 1)];
    }
    if (limit != size + bottom_left_size) {
        left[size + bottom_left_size - 1] = src[(-1) + stride * (size + bottom_left_size - 1)];
    }
}
