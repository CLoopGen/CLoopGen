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
    size_t i = 0;
    double temp_vol = 1.0;
    for (; i < dim; i += 2) {
        if (i + 1 < dim) {
            temp_vol *= (xu[i] - xl[i]) * (xu[i+1] - xl[i+1]);
        } else {
            temp_vol *= (xu[i] - xl[i]);
        }
    }
    vol = temp_vol;
}
