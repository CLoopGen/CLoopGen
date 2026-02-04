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
    double local_k = k;
    double local_mean = mean;
    for (i = ilow; i <= ihigh; ++i) {
        double delta = (double)(i * i); // Introduce new computation independent of prior iterations
        local_k += 1.0;
        local_mean += delta / local_k; // Update local accumulator to remove loop-carried dependency on global mean and k
    }
    k = local_k;
    mean = local_mean; // Write back final values after loop
}
