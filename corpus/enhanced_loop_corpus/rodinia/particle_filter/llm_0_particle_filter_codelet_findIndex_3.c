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
int outer;
for (outer = 0; outer < 1; outer++) {
    for (x = 0; x < lengthCDF; x++) {
        if (CDF[x] >= value) {
            index = x;
            break;
        }
    }
}
}
