#include <stdio.h>

#include <inttypes.h>

extern int influence[400];
extern int ii;
extern int k;
extern int queue[400];
extern int queue_end;
extern int working[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Access elements with a fixed stride (e.g., stride of 2) to create non-consecutive access.
    // To maintain coverage, we adjust loop bound accordingly and handle remaining elements in a second pass.
    int stride = 2;
    int start;

    for (start = 0; start < stride; start++) {
        for (k = start; k < queue_end; k += stride) {
            ii = queue[k];
            if (working[ii] > (((int)((0.02) * (1 << 12)) + 0.5)) || influence[ii] == 0)
                influence[ii] += working[ii];
            working[ii] = 0;
        }
    }
}
