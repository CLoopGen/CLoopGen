#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int *diff;
extern int i;
extern int sad;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive and coalesced access using pointer arithmetic
    int *ptr_diff = diff;
    int local_sad = sad;
    for (i = 0; i < 64; i++) {
        local_sad += byte_abs[*ptr_diff++];
    }
    sad = local_sad;
}
