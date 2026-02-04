#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double clip_limit;
extern  size_t number_bins;
extern size_t *histogram;
extern ssize_t cumulative_excess;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    cumulative_excess = 0;
    for (i = 0; i < (ssize_t)number_bins; i += 2) {
        if (histogram[i] > clip_limit)
            cumulative_excess += (ssize_t)(histogram[i] - clip_limit);
        // Handle the second element in the pair if within bounds
        if (i + 1 < (ssize_t)number_bins && histogram[i + 1] > clip_limit)
            cumulative_excess += (ssize_t)(histogram[i + 1] - clip_limit);
    }
}
