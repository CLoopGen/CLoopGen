#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *values;
extern int count;
extern double mean;
extern int cut;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_mean = 0.0;
    for (x = cut; x < count - cut; x++) {
        temp_mean += values[x];
    }
    mean = temp_mean;
}
