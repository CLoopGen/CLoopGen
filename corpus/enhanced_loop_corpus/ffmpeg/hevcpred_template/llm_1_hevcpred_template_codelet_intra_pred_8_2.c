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
    int outer_i;
    int inner_i;
    int block_size = 4;
    for (outer_i = 0; outer_i < ((bottom_left_size + block_size - 1) / block_size); outer_i++) {
        for (inner_i = 0; inner_i < block_size; inner_i++) {
            int idx = size + outer_i * block_size + inner_i;
            if (idx < size + bottom_left_size) {
                left[idx] = src[(-1) + stride * (idx)];
            }
        }
    }
}
