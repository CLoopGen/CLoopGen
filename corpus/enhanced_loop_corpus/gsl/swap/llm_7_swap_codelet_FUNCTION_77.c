#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern size_t p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = 0;
    for (p = 0; p < size1; p++) {
        size_t k = temp + p; // Loop-carried WAW/RAW dependency via temp
        size_t r = k * k;
        size_t c = r / (p + 1);
        temp = c; // Loop-carried dependency: temp used in next iteration
        // Introduces loop-carried flow dependence (RAW) through temp
    }
}
