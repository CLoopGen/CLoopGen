#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double alpha;
extern double *x;
extern double *y;
extern int i;
extern int len4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len4; i++) {
        double temp1 = alpha * x[4 * i];
        double temp2 = alpha * x[4 * i + 1];
        double temp3 = alpha * x[4 * i + 2];
        double temp4 = alpha * x[4 * i + 3];

        y[4 * i] += temp1;
        y[4 * i + 1] += temp2;
        y[4 * i + 2] += temp3;
        y[4 * i + 3] += temp4;

        // Additional computational work to increase arithmetic intensity
        temp1 *= 0.5;
        temp2 *= 0.5;
        temp3 *= 0.5;
        temp4 *= 0.5;

        y[4 * i] -= temp1;
        y[4 * i + 1] -= temp2;
        y[4 * i + 2] -= temp3;
        y[4 * i + 3] -= temp4;
    }
}
