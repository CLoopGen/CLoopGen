#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double qq;
extern double aa;
extern double term;
extern int ii;
extern int n1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern simulation using step of 2 with bounds handling
    // Here we simulate a strided access by processing every second element in a conceptual array,
    // while maintaining the same recurrence logic. We adjust loop bound to ensure valid ii usage.
    int stride = 2;
    int upper = n1 / stride;
    double temp_term = term; // Use local accumulator to preserve dependency
    for (ii = 0; ii < upper; ii++) {
        int idx = ii * stride; // Strided index mapping
        temp_term = qq * qq / (aa - 4. * (idx + 1) * (idx + 1) - temp_term);
    }
    term = temp_term; // Update global term once at end
}
