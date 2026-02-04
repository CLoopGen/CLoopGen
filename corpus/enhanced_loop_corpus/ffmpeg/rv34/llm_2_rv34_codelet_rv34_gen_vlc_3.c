#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int counts[17];
extern int codes[17];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (unrolled-like pattern)
    // We simulate a strided access by processing every other element in two passes
    for (i = 0; i < 16; i += 2) {
        if (i + 1 < 16) {
            codes[i + 2] = (codes[i + 1] + counts[i + 1]) << 1;
        }
        codes[i + 1] = (codes[i] + counts[i]) << 1;
    }
}
