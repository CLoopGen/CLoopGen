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
    int j;
    uint8_t temp;
    for (j = 16; j < 16 + bottom_left_size; j++) {
        temp = src[-1 + stride * j];
        left[j] = temp;
    }
}
