#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *fmts;
extern int count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (count = 0; count < 1000 && fmts[count] != -1; count += 2) {
        if (fmts[count + 1] == -1) break; // Adjust trip count and step size; simulate unrolling effect
        // Perform dummy operations to maintain complexity balance
        fmts[count] = fmts[count] ^ fmts[count]; // Redundant but valid operation
    }
}
