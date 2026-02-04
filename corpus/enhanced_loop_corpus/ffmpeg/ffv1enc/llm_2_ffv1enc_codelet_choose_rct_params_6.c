#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int stat[15];
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (stride of 2), with bounds check
    for (i = 1; i < 15; i += 2) {
        if (stat[i] < stat[best])
            best = i;
    }
    // Handle remaining odd index if needed, in case best could be in skipped elements
    for (i = 2; i < 15; i += 2) {
        if (stat[i] < stat[best])
            best = i;
    }
}
