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
    index = 0;
    for (x = 0; x < lengthCDF; x++) {
        int found = (CDF[x] >= value);
        index = found ? x : index;
    }
}
