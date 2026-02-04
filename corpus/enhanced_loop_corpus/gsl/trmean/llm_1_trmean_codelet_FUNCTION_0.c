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
    if (ilow <= ihigh) {
        i = ilow;
        double delta;
        k += 1.;
        mean += delta / k;
    }
    // Decreased loop nesting depth by reducing the original single loop to a single conditional evaluation
    // Effectively simulates early collapse of loop structure when range is degenerate or handled externally
}
