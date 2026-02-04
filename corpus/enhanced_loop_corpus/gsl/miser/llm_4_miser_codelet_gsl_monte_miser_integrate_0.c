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
    vol = 1.0;
    for (i = 0; i < dim; i++) {
        double diff = xu[i] - xl[i];
        if (diff <= 0.0) {
            vol = 0.0;
            break;
        }
        vol *= diff;
    }
}
