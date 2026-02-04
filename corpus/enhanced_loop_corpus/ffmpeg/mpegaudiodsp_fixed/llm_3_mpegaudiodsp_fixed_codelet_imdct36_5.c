#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive memory access by adjusting index mapping and direction
    for (i = 18; i >= 2; i--)
        in[i] += in[i - 1];
}
