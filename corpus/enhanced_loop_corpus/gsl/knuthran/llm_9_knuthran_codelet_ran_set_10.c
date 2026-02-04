#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced trip count and simplified condition with unrolled-like behavior
    for (j = 150; j >= 120; j--) {
        if (((x[j]) & 1)) {
            // Combined operations into a single temporary computation to reduce redundancy
            long temp = (x[j]) & ((1L << 30) - 1);
            x[j - 63] = (x[j - 63] - temp) & ((1L << 30) - 1);
            x[j - 100] = (x[j - 100] - temp) & ((1L << 30) - 1);
        }
    }
}
