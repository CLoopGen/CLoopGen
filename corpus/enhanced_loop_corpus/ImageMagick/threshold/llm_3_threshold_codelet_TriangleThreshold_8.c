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
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = (ssize_t)255; i >= 0; i--)
        if (histogram[i] > count) {
            max = i;
            count = histogram[i];
        }
}
