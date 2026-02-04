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
    int step = 2;
    for (x = 0; x < lengthCDF; x += step) {
        if (CDF[x] >= value) {
            index = x;
            break;
        }
        // Unroll and check next element if within bounds
        if ((x + 1) < lengthCDF && CDF[x + 1] >= value) {
            index = x + 1;
            break;
        }
    }
    // Handle potential case where break didn't occur and index not set
    if (x >= lengthCDF) {
        index = lengthCDF - 1;
    }
}
