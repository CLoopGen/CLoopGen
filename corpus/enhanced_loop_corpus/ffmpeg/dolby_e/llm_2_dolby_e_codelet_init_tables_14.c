#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float start_window[192];
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    for (i = 0; i < 192; i += 2) {
        window[256 + i] = start_window[i];
        if (i + 1 < 192) {
            window[256 + (i + 1)] = start_window[i + 1];
        }
    }
}
