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
    // Variant 2: Consecutive access using pointer arithmetic instead of indexing
    // Convert array references to pointer-based consecutive access
    integer *ctot_ptr = ctot;
    integer *coltyp_ptr = coltyp + 1;  // Start from coltyp[1]
    
    for (integer i = 0; i < 4; ++i) {
        *(coltyp_ptr + i) = *(ctot_ptr + i);
    }
}
