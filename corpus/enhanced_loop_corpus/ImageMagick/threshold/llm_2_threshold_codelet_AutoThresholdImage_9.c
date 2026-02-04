#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *histogram;
extern double sum;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i <= (ssize_t)255; i += 2) {
        sum += histogram[i];
        if (i + 1 <= 255) {
            sum += histogram[i + 1];
        }
    }
}
