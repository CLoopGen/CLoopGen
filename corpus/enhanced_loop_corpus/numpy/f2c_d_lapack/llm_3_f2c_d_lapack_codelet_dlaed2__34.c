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
    // Variant 2: Strided memory access in reverse order with stride of -1 (reverse sequential)
    for (j = 4; j >= 1; --j) {
        coltyp[j] = ctot[j - 1];
    }
}
