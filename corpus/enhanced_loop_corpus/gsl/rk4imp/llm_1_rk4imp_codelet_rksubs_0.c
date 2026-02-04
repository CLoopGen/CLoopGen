#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double y[];
extern  double fY[];
extern  double b[];
extern  size_t stage;
extern  size_t dim;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t total = dim * stage;
    size_t linear_idx = 0;
    for (i = 0; i < dim; i++)
        y[i] = 0.;

    for (size_t iter = 0; iter < total; iter++) {
        size_t local_dim = iter % dim;
        size_t local_stage = iter / dim;
        if (local_stage < stage)
            y[local_dim] += b[local_stage] * fY[iter];
    }
}
