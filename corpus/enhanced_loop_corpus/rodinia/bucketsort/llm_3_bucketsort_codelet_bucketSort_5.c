#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *h_offsets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward traversal with temporary accumulation (transformed to unit stride and cumulative pattern)
    unsigned int temp = h_offsets[0];
    for (int i = 1; i < (1 << 10); i++) {
        temp += h_offsets[i];
        h_offsets[i] = temp;
    }
}
