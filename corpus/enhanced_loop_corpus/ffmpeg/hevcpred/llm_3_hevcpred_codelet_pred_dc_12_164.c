#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern ptrdiff_t stride;
extern int i;
extern int j;
extern int size;
extern uint16_t *src;
extern uint64_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increased stride over j, stepping through non-unit strided locations
    // We modify the inner loop to jump by a larger stride (e.g., 8 instead of 4), and adjust effective access
    // to simulate sparse or strided pattern, possibly mimicking block-wise operations or down-sampling.
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j += 8)  // Increased stride in j-loop
            if (j + 4 <= size) // Ensure we don't go out of bounds for the 64-bit write (4x uint16_t = 8 bytes)
                ((((union unaligned_64 *)(&src[(j) + stride * (i)]))->l) = (a));
}
