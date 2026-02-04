#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride of 2
    // Process every second element in two passes to create strided pattern
    // First pass: even indices
    for (i = 0; i < 256; i += 2) {
        window[3008 + i] = window[959 - i];
    }
    // Second pass: odd indices
    for (i = 1; i < 256; i += 2) {
        window[3008 + i] = window[959 - i];
    }
}
