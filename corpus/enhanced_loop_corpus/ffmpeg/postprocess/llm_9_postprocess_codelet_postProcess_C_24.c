#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t * yHistogram;
extern uint64_t sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_sum = 0;
    for (i = 0; i < 128; i++) {
        local_sum += yHistogram[2*i] + yHistogram[2*i+1];
    }
    sum += local_sum;
}
