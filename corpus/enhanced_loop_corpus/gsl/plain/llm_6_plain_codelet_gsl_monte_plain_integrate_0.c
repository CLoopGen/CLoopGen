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
    double temp_vol = 1.0;
    for (i = 0; i < dim; i++) {
        temp_vol *= xu[i] - xl[i];
    }
    vol = temp_vol;
}
