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
    for (i = ilow; i <= ihigh; i += 2) {
        double delta1, delta2;
        k += 1.0;
        delta1 = (i % 3) * 0.1;
        mean += delta1 / k;
        
        if (i + 1 <= ihigh) {
            k += 1.0;
            delta2 = ((i + 1) % 3) * 0.1;
            mean += delta2 / k;
        }
    }
}
