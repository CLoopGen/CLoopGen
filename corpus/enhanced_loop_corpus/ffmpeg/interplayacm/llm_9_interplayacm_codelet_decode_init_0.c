#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int mul_3x3[27];
extern int x1;
extern int x2;
extern int x3;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x3 = 0; x3 < 2; x3++)  // Reduced trip count from 3 to 2
        for (x2 = 0; x2 < 4; x2++)  // Increased inner trip count from 3 to 4
            for (x1 = 0; x1 < 4; x1++) {
                int offset = x1 + (x2 << 2) + (x3 << 4); // Adjusted indexing arithmetic
                mul_3x3[offset] = (x1 & 1) + ((x2 & 2) << 3) + ((x3 & 1) << 7); // Simplified and altered computation
            }
}
