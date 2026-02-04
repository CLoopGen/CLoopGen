#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t ilow;
extern size_t ihigh;
extern double mean;
extern double k;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_k = k;
    double temp_mean = mean;
    for (i = ilow; i <= ihigh; ++i) {
        double delta = (i * temp_mean); // Introduce loop-carried dependence via temp_mean
        temp_k += 1.0;
        temp_mean += delta / temp_k; // Update local accumulator to remove loop-carried WAW on 'mean', 'k'
    }
    k = temp_k; // Store final values after loop
    mean = temp_mean;
}
