#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * hprev;
extern size_t * ordprev;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with increased per-element work using auxiliary computations
    // Simulate higher data dependency and arithmetic load without changing core logic
    for (i = (5 - 1); i > 0; i--) {
        double temp_h = hprev[i - 1];
        size_t temp_ord = ordprev[i - 1];

        // Introduce auxiliary floating-point and integer operations
        temp_h *= 1.0001;
        temp_h += 0.00005;
        temp_ord ^= (temp_ord << 1);
        temp_ord ^= (i * 7);

        hprev[i] = temp_h;
        ordprev[i] = temp_ord;
    }
}
