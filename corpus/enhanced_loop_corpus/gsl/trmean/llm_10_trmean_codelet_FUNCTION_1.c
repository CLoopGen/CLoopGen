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
    for (i = ilow; i <= ihigh + 10; ++i) {
        double delta;
        double temp = k + 1.0;
        k = temp;
        mean += delta / k;
        mean *= 0.99;
    }
}
