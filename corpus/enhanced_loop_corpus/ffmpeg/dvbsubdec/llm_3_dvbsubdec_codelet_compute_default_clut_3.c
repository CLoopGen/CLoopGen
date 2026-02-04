#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int (*counttab2)[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access across columns with fixed stride
    // We change access pattern to write to every second column, simulating strided access
    for (i = 0; i < 256; i += 2) {
        if (i + 1 < 256) {
            counttab2[i + 1][i] = 0;
        }
        if (i + 1 < 256 && i + 1 < 256) {
            counttab2[i + 1][i + 1] = 0;
        }
    }
    // Handle odd-sized tail if needed, but since 256 is even, loop covers all relevant cases
}
