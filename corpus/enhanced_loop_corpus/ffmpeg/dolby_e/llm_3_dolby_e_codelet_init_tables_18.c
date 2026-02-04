#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write, reverse read access pattern
    for (i = 0; i < 192; i++) {
        int reversed_index = 191 - i;  // Reverse the source index
        window[768 + i] = window[64 + reversed_index];
    }
}
