#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x_sum[10];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    for (k = 0; k < 10; k += 2)
        x_sum[k] = 0.;
    for (k = 1; k < 10; k += 2)
        x_sum[k] = 0.;
}
