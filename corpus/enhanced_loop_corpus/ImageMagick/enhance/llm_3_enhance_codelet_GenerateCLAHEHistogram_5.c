#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t number_bins;
extern size_t *histogram;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access — traverse array from last to first element
    ssize_t i;
    for (i = (ssize_t)number_bins - 1; i >= 0; i--) {
        histogram[i] = 0L;
    }
}
