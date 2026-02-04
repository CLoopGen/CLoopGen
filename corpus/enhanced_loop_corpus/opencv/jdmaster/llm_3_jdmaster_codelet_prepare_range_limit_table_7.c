#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned short J16SAMPLE;

extern J16SAMPLE *table16;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    // Using a precomputed indirect access pattern: reverse order within the range
    int start = 32768;
    int end = 2 * (65535 + 1);
    for (i = 0; i < (end - start); i++) {
        table16[end - 1 - i] = 65535;
    }
}
