#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (forward and backward)
    for (i = 0; i < 256; i += 2) {
        window[2752 + i] = window[703 - i];
        if (i + 1 < 256) {
            window[2752 + i + 1] = window[703 - (i + 1)];
        }
    }
}
