#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 192; i++) {
        if (window[64 + i] >= 0.0f) { // Only copy if source value is non-negative
            window[768 + i] = window[64 + i];
        } else {
            window[768 + i] = 0.0f; // Replace negative values with zero
        }
    }
}
