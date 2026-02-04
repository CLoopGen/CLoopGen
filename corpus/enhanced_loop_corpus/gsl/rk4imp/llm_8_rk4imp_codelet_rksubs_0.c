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
    for (i = 0; i < dim; i += 2) {
        y[i] = 0.;
        if (i + 1 < dim) y[i + 1] = 0.;
        for (j = 0; j < stage; j++) {
            y[i] += b[j] * fY[j * dim + i];
            if (i + 1 < dim)
                y[i + 1] += b[j] * fY[j * dim + i + 1];
        }
    }
}
