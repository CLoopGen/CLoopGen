#include <stdio.h>

#include <inttypes.h>

extern char *row[6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (stride of 2, unrolled by processing two elements per iteration)
    int idx;
    for (idx = 0; idx < 6; idx += 2) {
        if (idx < 6) row[idx] = ((void *)0);
        if (idx + 1 < 6) row[idx + 1] = ((void *)0);
    }
}
