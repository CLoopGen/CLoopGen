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
    for (size_t outer = 0; outer < (size_t)number_bins; outer += 16) {
        for (size_t inner = outer; inner < outer + 16 && inner < number_bins; inner++) {
            i = (ssize_t)inner;
            if (histogram[i] > clip_limit) {
                cumulative_excess += (ssize_t)(histogram[i] - clip_limit);
            }
        }
    }
}
