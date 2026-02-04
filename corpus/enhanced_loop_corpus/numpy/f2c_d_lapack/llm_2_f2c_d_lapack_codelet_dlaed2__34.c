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
    // Variant 1: Consecutive memory access with offset indexing (unrolled by factor of 2)
    coltyp[1] = ctot[0];
    coltyp[2] = ctot[1];
    coltyp[3] = ctot[2];
    coltyp[4] = ctot[3];
}
