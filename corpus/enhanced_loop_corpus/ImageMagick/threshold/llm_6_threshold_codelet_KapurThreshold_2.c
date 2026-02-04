#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern double *cumulative_histogram;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t j;
    for (j = 0; j < 255; j++) {
        cumulative_histogram[j + 1] = cumulative_histogram[j] + histogram[j + 1];
    }
}
