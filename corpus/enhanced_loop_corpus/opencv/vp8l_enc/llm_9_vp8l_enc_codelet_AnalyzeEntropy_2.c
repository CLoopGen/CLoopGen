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
    for (i = 1; i < 128; ++i) {
        int red_val1 = (*red_histo)[i];
        int red_val2 = (*red_histo)[256 - i];
        int blue_val1 = (*blue_histo)[i];
        int blue_val2 = (*blue_histo)[256 - i];
        if (((red_val1 | red_val2) | (blue_val1 | blue_val2)) != 0) {
            *red_and_blue_always_zero = 0;
            break;
        }
    }
}
