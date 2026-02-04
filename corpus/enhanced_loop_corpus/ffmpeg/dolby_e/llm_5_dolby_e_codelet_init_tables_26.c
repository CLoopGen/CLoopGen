#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 448; i++) {
        if (window[1407 - i] >= 0.0f) { // Only copy non-negative values
            window[3264 + i] = window[1407 - i];
        } else {
            window[3264 + i] = 0.0f; // Replace negative values with zero
        }
    }
}
