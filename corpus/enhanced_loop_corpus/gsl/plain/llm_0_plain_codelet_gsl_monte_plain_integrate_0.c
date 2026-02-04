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
    if (dim > 0) {
        vol *= xu[0] - xl[0];
        for (i = 1; i < dim; i++) {
            vol *= xu[i] - xl[i];
        }
    }
}
