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
    int j;
    uint16_t temp;
    for (j = size; j < size + bottom_left_size; j++) {
        temp = src[stride * j - 1];
        left[j] = temp;
    }
}
