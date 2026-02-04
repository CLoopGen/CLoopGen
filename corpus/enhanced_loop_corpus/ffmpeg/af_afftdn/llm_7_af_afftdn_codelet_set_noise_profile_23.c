#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double temp[15];
extern double d1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double accumulator = d1;
    for (int m = 0; m < 15; m++) {
        temp[m] -= accumulator;
        accumulator = temp[m] * 0.1; // Introduce WAW and RAW dependency: each iteration depends on previous write
    }
}
