#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern  int16_t *vector;
extern int length;
extern int bits;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse-order memory access (backward traversal)
    for (i = length - 1; i >= 0; i--) {
        dst[i] = (vector[i] * (1 << bits)) >> 3;
    }
}
