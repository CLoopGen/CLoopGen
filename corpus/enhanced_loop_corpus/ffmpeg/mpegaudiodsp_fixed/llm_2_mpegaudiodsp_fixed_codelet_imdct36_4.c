#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with stride of 2 (backward iteration)
    // Access pattern: i, i-2, i-4, etc., ensuring bounds are respected
    for (i = 16; i >= 2; i -= 2) {
        in[i] += in[i - 2];
    }
}
