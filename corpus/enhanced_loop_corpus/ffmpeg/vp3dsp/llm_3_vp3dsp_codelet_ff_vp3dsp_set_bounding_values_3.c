#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int filter_limit;
extern int *bounding_values;
extern int x;
extern int value;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access (stride of 2) with offset indexing
    int stride = 2;
    int limit = 128 * stride;
    int val = value;
    for (int offset = filter_limit * stride; offset < limit && val; offset += stride, val--) {
        int pos_idx = offset / stride;
        bounding_values[pos_idx] = val;
        bounding_values[-pos_idx + filter_limit] = -val; // shifted negative index
    }
}
