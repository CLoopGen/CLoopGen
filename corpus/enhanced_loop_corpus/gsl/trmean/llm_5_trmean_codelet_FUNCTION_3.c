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
    double delta;
    k += 1.;
    if (k > 1.0) {
        mean += delta / k;
    }
}
}
