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
    int temp[256];
    int j;
    const int offset = -1;
    for (j = 0; j < bottom_left_size && j < 256; j++) {
        int idx = size + j;
        temp[j] = src[offset + stride * idx];
    }
    for (j = 0; j < bottom_left_size && j < 256; j++) {
        left[size + j] = temp[j];
    }
}
