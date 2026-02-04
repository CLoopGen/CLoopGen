#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern ptrdiff_t stride;
extern uint16_t *src;
extern uint16_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided write combined with strided read to simulate transposed-like access
    ptrdiff_t dst_stride = 2; // Simulate non-unit write stride
    int j = 0;
    for (i = 0; i < size; i++, j += dst_stride) {
        left[j] = src[-1 + stride * i];
    }
}
