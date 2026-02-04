#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double xl[];
extern  double xu[];
extern  size_t dim;
extern double vol;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    double local_vol = 1.0;
    const size_t unroll_factor = 4;
    size_t remainder = dim % unroll_factor;
    
    for (i = 0; i < remainder; i++) {
        local_vol *= xu[i] - xl[i];
    }
    
    for (; i <= dim - unroll_factor; i += unroll_factor) {
        local_vol *= (xu[i] - xl[i]) *
                     (xu[i+1] - xl[i+1]) *
                     (xu[i+2] - xl[i+2]) *
                     (xu[i+3] - xl[i+3]);
    }
    vol = local_vol;
}
