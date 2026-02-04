#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x_sum[10];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (k = 9; k >= 0; k--)
        x_sum[k] = 0.;
}
