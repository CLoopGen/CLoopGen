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
    // Variant 2: Strided memory access with stride over output index
    // Access the destination array in a strided manner (stride of 16) while maintaining logical equivalence
    // This increases spatial locality in source but creates stride in destination.
    int idx;
    for (idx = 0; idx < 128; idx++) {
        int i = idx / 16;
        int j = idx % 16;
        window[512 + idx] = window[64 * i + 32 - j];
    }
}
