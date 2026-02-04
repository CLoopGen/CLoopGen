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
    // Variant 1: Strided memory access (stride of 2)
    int stride = 2;
    index = -1; // Initialize to indicate not found
    for (x = 0; x < lengthCDF; x += stride) {
        if (CDF[x] >= value) {
            index = x;
            break;
        }
    }
    // Handle case where the exact match might be in the skipped element
    if (index == -1) {
        // Check last odd index if lengthCDF is odd
        for (x = 1; x < lengthCDF; x += 2) {
            if (CDF[x] >= value) {
                index = x;
                break;
            }
        }
    } else {
        // Refine search backward by one if previous element might qualify
        if (index > 0 && CDF[index - 1] >= value) {
            index = index - 1;
        }
    }
}
