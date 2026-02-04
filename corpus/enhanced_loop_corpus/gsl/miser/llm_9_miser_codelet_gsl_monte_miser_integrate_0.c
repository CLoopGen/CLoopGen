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
    for (size_t j = 0; j < dim * 2; j += 2) {
        size_t i = j / 2;
        vol *= (xu[i] - xl[i]);
    }
}
