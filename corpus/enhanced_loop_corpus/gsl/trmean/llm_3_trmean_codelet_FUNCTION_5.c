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
    size_t stride = 2;
    size_t j;
    for (j = ilow; j <= ihigh; j += stride) {
        double delta;
        k += 1.;
        mean += delta / k;
        if (j + 1 <= ihigh) {
            k += 1.;
            mean += delta / k;
        }
    }
}
