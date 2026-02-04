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
    // Variant 1: Consecutive memory access with offset base pointer
    integer *base_coltyp = coltyp + 1;
    for (j = 0; j < 4; ++j) {
        base_coltyp[j] = ctot[j];
    }
}
