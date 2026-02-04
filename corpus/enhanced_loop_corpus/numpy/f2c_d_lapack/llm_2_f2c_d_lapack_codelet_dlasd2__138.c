#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *coltyp;
extern integer j;
extern integer ctot[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with reverse traversal and stride of 2 (unrolled simulation)
    // Access pattern: j = 4, 2 (even indices only in descending order)
    integer j;
    for (j = 4; j >= 2; j -= 2) {
        coltyp[j] = ctot[j - 1];
    }
    // Handle remaining odd index if needed (j=3 and j=1)
    for (j = 3; j >= 1; j -= 2) {
        coltyp[j] = ctot[j - 1];
    }
}
