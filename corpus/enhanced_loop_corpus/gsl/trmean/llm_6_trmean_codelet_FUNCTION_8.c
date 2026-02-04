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
    for (i = ilow; i <= ihigh; ++i) {
        double delta = (i - mean); // Introduce RAW dependency: 'mean' is read before update
        k += 1.0;
        mean = mean + delta / k; // WAW on 'mean': write after prior write in same iteration
    }
}
