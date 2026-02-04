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
    double delta = 0.0;
    for (i = ilow; i <= ihigh; ++i) {
        delta += (double)(i); // Introduce loop-carried dependency on 'delta'
        k += 1.;
        mean += delta / k; // RAW dependency: 'delta' and 'k' used after write
    }
}
