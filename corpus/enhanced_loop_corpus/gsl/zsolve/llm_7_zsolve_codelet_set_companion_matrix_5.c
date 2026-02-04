#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t nc;
extern double *m;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (i = 1; i < nc; i++) {
        temp = 1.; // Remove direct loop-carried dependency by using local temp
        ((m)[(i) * (nc) + (i - 1)]) = temp; // Eliminates potential RAW if m were read later in same iteration
    }
}
