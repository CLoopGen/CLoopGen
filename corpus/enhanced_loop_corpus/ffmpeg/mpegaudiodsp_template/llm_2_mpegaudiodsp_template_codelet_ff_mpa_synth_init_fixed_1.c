#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t MPA_INT;

extern MPA_INT *window;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with stride transformation
    // Reorder inner loop to access memory sequentially by precomputing base indices
    MPA_INT *base;
    for (i = 0; i < 8; i++) {
        base = &window[64 * i + 32];
        for (j = 0; j < 16; j++) {
            window[512 + 16 * i + j] = base[-j];  // Reverse access from base
        }
    }
}
