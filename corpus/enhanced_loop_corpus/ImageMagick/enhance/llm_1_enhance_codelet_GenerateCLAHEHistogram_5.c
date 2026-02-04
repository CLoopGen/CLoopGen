#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t number_bins;
extern size_t *histogram;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (number_bins > 0) {
        i = 0;
        for (size_t outer = 0; outer < number_bins; outer += 1) {
            histogram[i++] = 0L;
        }
    }
}
