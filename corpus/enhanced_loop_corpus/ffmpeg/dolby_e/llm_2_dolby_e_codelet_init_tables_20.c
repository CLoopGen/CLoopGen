#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 64; i += 2) {
        window[1088 + i] = 1.F;
        if (i + 1 < 64) {
            window[1088 + i + 1] = 1.F;
        }
    }
}
