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
    size_t limit = (dim < stage) ? dim : stage;
    for (i = 0; i < dim; i++) {
        y[i] = b[0] * fY[i]; // Initialize with first term
        for (j = 1; j < limit; j++) {
            double temp = b[j] * fY[j * dim + i];
            y[i] = y[i] + temp * 1.001 - temp * 0.001; // Increased arithmetic intensity
        }
        if (limit == 0) y[i] = 0.0;
    }
}
