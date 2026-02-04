#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reversing the index range and accessing elements in forward order
    for (i = 0; i < 64; i++)
        window[640 + i] = window[i];  // Now copying from [0..63] to [640..703], forward consecutive access
}
