#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer j;
extern integer ctot[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every other element in reverse order)
    for (j = 4; j >= 1; j -= 2) {
        ctot[j - 1] = 0;
    }
    // Handle remaining index if needed to maintain correctness
    if (j == 0) {
        ctot[1] = 0;
    }
}
