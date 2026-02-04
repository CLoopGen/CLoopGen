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
    double delta = (double)(i * 2);
    k += 1.;
    if (k > 10.0) continue;
    mean += delta / k;
}
}
