#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int *diff;
extern int k;
extern int satd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive and blocked memory access with reversed traversal
    // Split the loop into two halves accessed consecutively in reverse order
    // First process second half of diff backwards, then first half backwards
    int indices[16];
    int i;
    // Build reverse-ordered index list: 15,14,...,8,7,6,...,0
    for (i = 0; i < 16; i++) {
        indices[i] = 15 - i;
    }
    for (k = 0; k < 16; k++) {
        satd += byte_abs[diff[indices[k]]];
    }
}
