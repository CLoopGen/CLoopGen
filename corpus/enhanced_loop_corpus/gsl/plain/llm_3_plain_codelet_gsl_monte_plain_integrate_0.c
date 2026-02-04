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
    size_t j;
    for (j = 0; j < dim; j += 2) {
        vol *= xu[j] - xl[j];
        if (j + 1 < dim) {
            vol *= xu[j + 1] - xl[j + 1];
        }
    }
}
