#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t * yHistogram;
extern uint64_t sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, processing even indices first, then odd
    sum = 0;
    for (i = 0; i < 256; i += 2) {
        sum += yHistogram[i];
    }
    for (i = 1; i < 256; i += 2) {
        sum += yHistogram[i];
    }
}
