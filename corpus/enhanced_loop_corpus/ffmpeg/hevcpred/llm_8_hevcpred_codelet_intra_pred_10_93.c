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
    for (j = 0; j < bottom_left_size; j += 2) {
        int idx1 = size + j;
        int idx2 = size + j + 1;
        ptrdiff_t src_idx1 = (-1) + stride * idx1;
        left[idx1] = src[src_idx1];
        if (j + 1 < bottom_left_size) {
            ptrdiff_t src_idx2 = (-1) + stride * idx2;
            left[idx2] = src[src_idx2];
        }
    }
}
