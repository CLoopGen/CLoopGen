#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *fmts;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2, then adjust if needed)
    int step = 2;
    count = 0;
    for (; fmts[count] != -1; count += step) {
        // Handle potential -1 hit on even index
        if (fmts[count] == -1) break;
        // Check intermediate element if within bounds
        if (count + 1 < (1 << 20) && fmts[count + 1] == -1) { // Arbitrary large bound to avoid segfault
            count++;
            break;
        }
    }
}
