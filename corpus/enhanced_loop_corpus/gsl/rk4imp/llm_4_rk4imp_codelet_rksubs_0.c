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
        y[i] = 0.;
        if (dim > 100 && i % 10 == 0) {
            for (j = 0; j < stage; j += 2) {
                y[i] += b[j] * fY[j * dim + i];
                if (j + 1 < stage)
                    y[i] += b[j + 1] * fY[(j + 1) * dim + i];
            }
        } else {
            for (j = 0; j < stage; j++)
                y[i] += b[j] * fY[j * dim + i];
        }
    }
}
