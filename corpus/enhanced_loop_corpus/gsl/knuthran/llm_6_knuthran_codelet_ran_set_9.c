#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 198; j > 63; j -= 2) {
        int idx = 199 - 1 - j;
        long temp = x[j];
        x[idx] = (temp & ((1L << 30) - 2));
        x[j] = temp ^ 0x1; // Introduce WAW dependency: write after previous use of x[j]
    }
}
