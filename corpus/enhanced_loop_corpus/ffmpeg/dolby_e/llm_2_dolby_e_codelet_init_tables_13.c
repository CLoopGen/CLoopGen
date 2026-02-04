#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 128; i += 2) {
        if (i + 1 < 128) {
            window[128 + i] = window[127 - i];
            window[128 + i + 1] = window[127 - i - 1];
        } else {
            window[128 + i] = window[127 - i];
        }
    }
}
