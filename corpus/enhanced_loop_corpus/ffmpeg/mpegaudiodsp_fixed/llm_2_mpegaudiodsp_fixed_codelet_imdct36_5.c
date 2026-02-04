#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with increased stride and offset adjustment
    for (i = 16; i >= 4; i -= 4)
        in[i] += in[i - 4];
}
