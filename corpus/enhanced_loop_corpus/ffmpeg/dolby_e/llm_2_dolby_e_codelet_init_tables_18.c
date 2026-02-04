#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern __attribute__((aligned(32))) float window[3712];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < 192; i += 2) {
        if (i + 1 < 192) {
            window[768 + i] = window[64 + i];
            window[768 + i + 1] = window[64 + i + 1];
        } else {
            window[768 + i] = window[64 + i];
        }
    }
}
