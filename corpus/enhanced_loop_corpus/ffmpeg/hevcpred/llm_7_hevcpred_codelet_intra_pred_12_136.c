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
    int k;
    for (k = size; k < size + bottom_left_size; k++) {
        left[k] = src[stride * (k + 1) - 1];
        if (k > size) {
            left[k] += left[k - 1]; 
        }
    }
}
