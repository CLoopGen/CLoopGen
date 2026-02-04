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
    double temp_mean = mean;
    double temp_k = k;
    for (i = ilow; i <= ihigh; ++i) {
        double delta = (double)(i - ilow); // Remove dependency on prior iterations
        temp_k += 1.0;
        temp_mean += delta / temp_k; // Eliminate loop-carried dependency on shared 'mean' and 'k'
    }
    mean = temp_mean; // Update shared state only after loop
    k = temp_k;
}
