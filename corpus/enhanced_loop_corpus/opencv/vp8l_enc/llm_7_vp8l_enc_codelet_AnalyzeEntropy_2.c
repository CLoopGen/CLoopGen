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
    int local_flag = *red_and_blue_always_zero;
    for (i = 1; i < 256; ++i) {
        if (((*red_histo)[i] | (*blue_histo)[i]) != 0) {
            local_flag = 0;
        }
    }
    *red_and_blue_always_zero = local_flag;
}
