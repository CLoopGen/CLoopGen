#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern double count;
extern ssize_t i;
extern ssize_t max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_count = count;
    ssize_t temp_max = max;
    for (i = 0; i <= (ssize_t)255; i++) {
        double val = histogram[i];
        if (val > temp_count) {
            temp_count = val;
            temp_max = i;
        }
    }
    max = temp_max;
    count = temp_count;
}
