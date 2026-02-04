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
    for (i = 0; i < dim; i++) {
        double sum1 = 0., sum2 = 0.;
        size_t half_stage = stage / 2;
        for (j = 0; j < half_stage; j++) {
            sum1 += b[j] * fY[j * dim + i];
            sum2 += b[stage - 1 - j] * fY[(stage - 1 - j) * dim + i];
        }
        y[i] = sum1 + sum2;
        if (stage % 2 == 1)
            y[i] += b[half_stage] * fY[half_stage * dim + i];
    }
}
