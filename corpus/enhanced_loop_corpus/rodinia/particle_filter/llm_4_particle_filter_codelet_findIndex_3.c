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
    index = lengthCDF; // Initialize to an invalid index
    for (x = 0; x < lengthCDF && index == lengthCDF; x++) {
        index = (CDF[x] >= value) ? x : index;
    }
    if (index == lengthCDF) index = -1; // Indicate not found
}
