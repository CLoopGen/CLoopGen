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
    size_t step = 2;
    for (i = 0; i < dim; i += step) {
        vol *= xu[i] - xl[i];
        if (i + 1 < dim) {
            vol *= xu[i + 1] - xl[i + 1];
        }
    }
}
