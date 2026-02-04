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
        double delta;
        local_k += 1.;
        delta = (i & 1) ? (double)i : -((double)i); // Introduce defined value for delta to maintain validity
        local_mean = local_mean + delta / local_k;
    }
    k = local_k;
    mean = local_mean;
}
