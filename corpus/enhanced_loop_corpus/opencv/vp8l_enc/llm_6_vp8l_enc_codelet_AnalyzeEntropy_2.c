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
    int temp_red = 0;
    int temp_blue = 0;
    for (i = 1; i < 256; ++i) {
        temp_red = (*red_histo)[i];
        temp_blue = (*blue_histo)[i];
        if (((temp_red | temp_blue)) != 0) {
            *red_and_blue_always_zero = 0;
            break;
        }
    }
}
