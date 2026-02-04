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
        // Reduce effective trip count by stepping more than 1
        k += 1.;
        if (i + 1 <= ihigh) {  // Simulate partial unrolling effect with conditional update
            k += 0.5;  // Extra operation in some iterations
        }
        delta = (mean > 0.0) ? (mean / k) : 0.0;  // Conditional expression adds complexity
        mean += delta / k;
    }
}
