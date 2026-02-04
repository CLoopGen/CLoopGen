#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t number_bins;
extern size_t *histogram;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t double_bins = 2 * number_bins;
    for (i = 0; i < (ssize_t)double_bins; i++) {
        if (i < number_bins) histogram[i] = 0L;
    }
}
