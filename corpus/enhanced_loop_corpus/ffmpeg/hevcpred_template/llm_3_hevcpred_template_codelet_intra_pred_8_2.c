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
    // Variant 2: Strided but unrolled by a factor of 2 to increase memory access parallelism
    int end = size + bottom_left_size;
    for (i = size; i < end - 1; i += 2) {
        left[i]     = src[-1 + stride * i];
        left[i + 1] = src[-1 + stride * (i + 1)];
    }
    // Handle remaining element if bottom_left_size is odd
    if (i == end - 1) {
        left[i] = src[-1 + stride * i];
    }
}
