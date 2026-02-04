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
        k += 0.5;
        mean += delta / k;
        if (i % 2 == 0) {
            mean += delta * 0.1;
        }
    }
}
