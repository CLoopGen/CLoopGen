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
    double temp_sum = 0.0;
    for (i = ilow; i <= ihigh; ++i) {
        double delta;
        local_k += 1.;
        temp_sum += delta;
    }
    k = local_k;
    mean += temp_sum / k;
}
