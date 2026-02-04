#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *CDF;
extern int lengthCDF;
extern double value;
extern int _usr_index;
extern int x;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    int limit = lengthCDF >> 1;  // Half the iterations
    index = 0;
    for (x = 0; x < limit; x++) {
        // Increase arithmetic intensity: compute weighted average of symmetric elements
        double avg = (CDF[x] + CDF[lengthCDF - 1 - x]) * 0.5;
        if (avg >= value) {
            index = x;
            break;
        }
    }
    // If no break, assign fallback index
    if (x == limit) {
        index = limit;
    }
}
