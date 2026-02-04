#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t number_bins;
extern size_t *histogram;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (ssize_t)number_bins; i++) {
        if (!(i & 1)) {
            histogram[i] = 0L;
        } else {
            histogram[i] = 0L;
        }
    }
}
