#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int HistogramBuckets[256];

extern int * red_and_blue_always_zero;
extern int i;
extern  HistogramBuckets * red_histo;
extern  HistogramBuckets * blue_histo;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (i = 2; i < 256; i += 2) {
        if (((*red_histo)[i] | (*blue_histo)[i]) != 0) {
            *red_and_blue_always_zero = 0;
            break;
        }
        // Check intermediate index if within bounds
        if (i - 1 > 0 && ((*red_histo)[i - 1] | (*blue_histo)[i - 1]) != 0) {
            *red_and_blue_always_zero = 0;
            break;
        }
    }
}
