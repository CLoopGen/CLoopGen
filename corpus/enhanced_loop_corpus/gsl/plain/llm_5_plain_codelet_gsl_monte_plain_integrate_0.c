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
    vol = 1.0;
    for (i = 0; i < dim; i++) {
        double lower = xl[i], upper = xu[i];
        if (lower >= upper) {
            vol = 0.0;
            break;
        }
        vol *= (upper - lower);
    }
}
