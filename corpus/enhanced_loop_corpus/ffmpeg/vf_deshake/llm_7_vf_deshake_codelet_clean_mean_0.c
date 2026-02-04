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
    double local_mean = mean;
    for (x = cut; x < count - cut; x += 2) {
        if (x + 1 < count - cut) {
            local_mean += values[x] + values[x + 1];
        } else {
            local_mean += values[x];
        }
    }
    mean = local_mean;
}
