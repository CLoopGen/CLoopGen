#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse)
    for (j = 100; j > 0; j -= 2) {
        if (j >= 2) {
            x[j] = x[j - 2];
        }
    }
}
