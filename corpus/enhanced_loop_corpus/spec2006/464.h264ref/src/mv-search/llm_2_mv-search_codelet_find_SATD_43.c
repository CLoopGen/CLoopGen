#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int i;
extern int sad;
extern int block_size_x;
extern int block_size_y;
extern int diff[256];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with loop unrolling by 2
    int n = block_size_y * block_size_x;
    int remainder = n % 2;
    int limit = n - remainder;

    for (i = 0; i < limit; i += 2) {
        sad += byte_abs[diff[i]] + byte_abs[diff[i + 1]];
    }
    // Handle remaining element if any
    for (; i < n; i++) {
        sad += byte_abs[diff[i]];
    }
}
