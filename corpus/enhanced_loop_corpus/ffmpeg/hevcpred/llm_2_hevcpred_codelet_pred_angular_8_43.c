#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mode;
extern int x;
extern  uint8_t *top;
extern  int inv_angle[];
extern uint8_t *ref_tmp;
extern int last;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing ref_tmp and top in potentially dense pattern, we modify the access to use a stride of 2
    // This reduces the number of memory operations and changes spatial locality.
    // We also adjust loop bounds accordingly to stay within valid range assuming sufficient buffer size.
    int stride = 2;
    for (x = last; x <= -1; x += stride)
        if (x + stride/2 <= 0) // Ensure we don't exceed bounds
            ref_tmp[x] = top[-1 + ((x * inv_angle[mode - 11] + 128) >> 8)];
}
