#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset shift
    // Instead of accessing x[j + j] and x[j + j - 1], rewrite to write consecutive elements
    // by reindexing: store x[j] into x[2*j] and zero the prior location x[2*j - 1]
    // Now we traverse j in reverse but write to a forward-moving even-odd pair
    for (j = 100 - 1; j > 0; j--) {
        long temp = x[j];
        x[2 * j] = temp;
        x[2 * j - 1] = 0;
    }
}
