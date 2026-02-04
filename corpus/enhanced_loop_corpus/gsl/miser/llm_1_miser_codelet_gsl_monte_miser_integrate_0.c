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
    size_t outer;
    for (outer = 0; outer < 1; outer++) {
        for (i = 0; i < dim; i++) {
            vol *= xu[i] - xl[i];
        }
    }
}
