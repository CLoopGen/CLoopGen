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
    for (i = ilow; i <= ihigh; ++i) {
        double delta;
        temp_mean += delta / (k + 1.);
        k += 1.;
    }
    mean = temp_mean;
}
