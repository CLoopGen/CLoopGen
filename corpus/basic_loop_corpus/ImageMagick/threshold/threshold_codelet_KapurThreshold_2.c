#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *histogram;
extern double *cumulative_histogram;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 1; i <= 255; i++)
    cumulative_histogram[i] = cumulative_histogram[i - 1] + histogram[i];

}
