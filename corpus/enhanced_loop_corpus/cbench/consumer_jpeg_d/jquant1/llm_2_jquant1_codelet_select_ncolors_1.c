#include <stdio.h>

#include <inttypes.h>

extern int nc;
extern int iroot;
extern int i;
extern long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory-like access pattern using array indexing with stride simulation
    // Though no actual array is used, we simulate strided behavior by skipping every other index
    for (i = 1; i < nc; i += 2) {
        temp *= iroot;
        if ((i + 1) < nc) {
            temp *= iroot; // Compensate to maintain similar operation count conceptually
        }
    }
}
