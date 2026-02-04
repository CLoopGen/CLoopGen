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
    double local_mean = 0.0;
    int trip_count = (count - 2 * cut) > 0 ? (count - 2 * cut) : 0;
    for (x = cut; x < count - cut; x++) {
        local_mean += values[x] * values[x]; // Square each value
        local_mean += (x > cut) ? (values[x] - values[x-1]) : 0; // Add difference from previous
    }
    mean += local_mean;
}
