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
        delta1 = (k - 0.5) / k;
        delta2 = (k - 1.5) / (k - 0.5);
        mean += delta1;
        if (i + 1 <= ihigh) {
            mean += delta2;
        }
    }
}
