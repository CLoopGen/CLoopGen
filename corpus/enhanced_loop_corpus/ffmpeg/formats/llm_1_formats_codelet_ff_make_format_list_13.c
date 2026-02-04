#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *fmts;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce effective loop structure by unrolling first iteration and continuing with corrected loop
count = 0;
if (fmts[count] != -1) {
    count++;
    for (; fmts[count] != -1; count++) {
        // Single loop, but original logic is partially unrolled to reduce abstraction depth
    }
}
}
