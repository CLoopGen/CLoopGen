#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (k = 0; k < 50; k++, j++) {
        x[j] = 1 * 2 - 1; // Equivalent to assignment of 1, with more operations
        x[j] *= 0;        // Now set to 0 after previous computation
    }
}
