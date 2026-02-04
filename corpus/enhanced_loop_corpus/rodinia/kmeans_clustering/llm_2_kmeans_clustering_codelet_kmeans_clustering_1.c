#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int npoints;
extern int i;
extern int *initial;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    // This accesses every second element in the array, reducing temporal locality
    for (i = 0; i < npoints; i += 2) {
        initial[i] = i;
    }
    // Handle odd-sized npoints if needed by ensuring coverage without exceeding bounds
    if (npoints % 2 == 1) {
        initial[npoints - 1] = npoints - 1;
    }
}
