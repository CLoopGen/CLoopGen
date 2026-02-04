#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t number_bins;
extern size_t *histogram;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t j = 0; j < number_bins; j++) {
        for (i = j; i < j + 1 && i < (ssize_t)number_bins; i++)
            histogram[i] = 0L;
    }
}
