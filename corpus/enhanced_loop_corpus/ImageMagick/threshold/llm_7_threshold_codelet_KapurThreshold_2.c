#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern double *cumulative_histogram;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t i;
    double temp[256] = {0};
    temp[0] = cumulative_histogram[0];
    for (i = 1; i <= 255; i++) {
        temp[i] = temp[i - 1] + histogram[i];
    }
    for (i = 1; i <= 255; i++) {
        cumulative_histogram[i] = temp[i];
    }
}
