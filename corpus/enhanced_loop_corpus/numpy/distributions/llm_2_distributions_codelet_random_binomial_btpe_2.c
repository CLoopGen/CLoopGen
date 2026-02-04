#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double a;
extern double s;
extern double F;
extern int64_t m;
extern int64_t y;
extern int64_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern (simulated via step size > 1)
    // Here, we simulate a strided iteration by increasing index in steps of 2
    // This modifies the memory access pattern to non-consecutive indices
    int64_t step = 2;
    for (i = m + 1; i <= y; i += step) {
        F *= (a / i - s);
        // Perform same operation on next element if within bounds to simulate use
        if (i + 1 <= y) {
            F *= (a / (i + 1) - s);
        }
    }
}
