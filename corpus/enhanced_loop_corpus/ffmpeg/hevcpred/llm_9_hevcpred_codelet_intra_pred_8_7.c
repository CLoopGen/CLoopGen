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
int step = 2;
for (i = size; i < size + bottom_left_size; i += step) {
    left[i] = src[stride * i - 1];
    if (i + 1 < size + bottom_left_size) {
        left[i + 1] = src[stride * (i + 1) - 1];
    }
}
}
