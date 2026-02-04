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
        double sum1 = 0.0, sum2 = 0.0;
        for (j = 0; j < stage - (stage % 2); j += 2) {
            sum1 += b[j]     * fY[j     * dim + i];
            sum2 += b[j + 1] * fY[(j + 1) * dim + i];
        }
        y[i] = sum1 + sum2;
        if (stage % 2 != 0) {
            y[i] += b[stage - 1] * fY[(stage - 1) * dim + i];
        }
    }
}
