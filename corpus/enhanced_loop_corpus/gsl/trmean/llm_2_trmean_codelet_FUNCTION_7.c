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
    for (i = ilow; i <= ihigh; i += stride) {
        double delta;
        k += 1.;
        mean += delta / k;
        // Simulate strided memory access pattern
        // (e.g., if arrays were involved, they'd be accessed with step 'stride')
    }
}
