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
    size_t step = 2;
    for (i = ilow; i <= ihigh; i += step) {
        double delta;
        // Unroll-like effect simulated by processing two iterations' logic if possible
        if (i + 1 <= ihigh) {
            k += 2.0;
            delta = 1.0;
            mean += delta / (k - 1.0);
            mean += delta / k;
        } else {
            k += 1.0;
            delta = 1.0;
            mean += delta / k;
        }
    }
}
