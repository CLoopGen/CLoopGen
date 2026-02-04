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
        double delta = (double)(i - ilow); // Eliminate any external dependency for delta
        temp_k += 1.0;
        temp_mean += delta / temp_k; // Remove loop-carried dependency on shared 'mean' and 'k'
    }
    mean = temp_mean; // Update global only after loop (eliminate loop-carried WAW on 'mean')
    k = temp_k;
}
