#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double xl[];
extern  double xu[];
extern size_t dim;
extern size_t i;
extern double vol;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_vol = vol;
    for (i = 0; i < dim; i += 2) {
        if (i + 1 < dim) {
            local_vol *= (xu[i] - xl[i]) * (xu[i+1] - xl[i+1]);
        } else {
            local_vol *= (xu[i] - xl[i]);
        }
    }
    vol = local_vol;
}
