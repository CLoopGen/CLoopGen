#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern double *cumulative_histogram;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ssize_t j = 1; j <= 255; j++) {
    for (ssize_t i = j; i <= j; i++) {
        cumulative_histogram[i] = cumulative_histogram[i - 1] + histogram[i];
    }
}
}
