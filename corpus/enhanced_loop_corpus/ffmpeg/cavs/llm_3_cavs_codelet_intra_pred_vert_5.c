#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern ptrdiff_t stride;
extern int y;
extern uint64_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (strided access through pointer offsets)
    ptrdiff_t indices[8] = {0, stride, 2*stride, 3*stride, 4*stride, 5*stride, 6*stride, 7*stride};
    for (y = 0; y < 8; y++)
        *((uint64_t *)(d + indices[y])) = a;
}
