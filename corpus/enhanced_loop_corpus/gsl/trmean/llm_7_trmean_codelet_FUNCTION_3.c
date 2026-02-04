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
    double accumulator = 0.0;
    for (i = ilow; i <= ihigh; ++i) {
        double delta = (double)(i * i);
        accumulator += delta / (local_k + 1.0);
        local_k += 1.0;
    }
    mean += accumulator;
    k = local_k;
}
