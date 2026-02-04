#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float MPA_INT;

extern MPA_INT *window;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access — write with stride of 8, effectively scattering writes
    for (j = 0; j < 16; j++) {
        for (i = 0; i < 8; i++) {
            // Transpose the access pattern: iterate over i inner, j outer, creating strided writes
            window[512 + 128 + 16 * i + j] = window[64 * i + 48 - j];
        }
    }
}
