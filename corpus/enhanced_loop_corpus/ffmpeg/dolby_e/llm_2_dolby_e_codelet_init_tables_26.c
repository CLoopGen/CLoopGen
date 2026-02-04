#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (forward and backward)
    // We traverse half the original range but access elements with a step of 2
    for (i = 0; i < 224; i++) {
        int forward_index = 3264 + 2 * i;
        int backward_index = 1407 - 2 * i;
        window[forward_index] = window[backward_index];
        // Fill in the odd indices as well to cover full 448 elements
        if (forward_index + 1 < 3712 && backward_index - 1 >= 0) {
            window[forward_index + 1] = window[backward_index - 1];
        }
    }
}
