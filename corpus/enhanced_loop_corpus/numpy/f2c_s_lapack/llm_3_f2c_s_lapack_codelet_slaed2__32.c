#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern integer *coltyp;
extern integer i__1;
extern integer j;
extern integer ct;
extern integer ctot[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // Assuming we simulate indirect access by accessing elements in reverse order
    for (j = i__1; j >= 1; --j) {
        ct = coltyp[j];
        ++ctot[ct - 1];
    }
}
