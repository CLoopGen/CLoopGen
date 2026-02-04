#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *histogram;
extern double sum;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_sum1 = 0.0, local_sum2 = 0.0;
    for (i = 0; i <= (ssize_t)127; i++) {
        local_sum1 += histogram[2*i];
        local_sum2 += histogram[2*i + 1];
    }
    sum = local_sum1 + local_sum2;
}
