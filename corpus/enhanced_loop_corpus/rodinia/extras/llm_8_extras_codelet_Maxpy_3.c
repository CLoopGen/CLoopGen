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
    for (i = 0; i < len4; i += 2) {
        if (i + 1 < len4) {
            y[4 * i] += alpha * x[4 * i];
            y[4 * i + 1] += alpha * x[4 * i + 1];
            y[4 * i + 2] += alpha * x[4 * i + 2];
            y[4 * i + 3] += alpha * x[4 * i + 3];

            y[4 * (i + 1)] += alpha * x[4 * (i + 1)];
            y[4 * (i + 1) + 1] += alpha * x[4 * (i + 1) + 1];
            y[4 * (i + 1) + 2] += alpha * x[4 * (i + 1) + 2];
            y[4 * (i + 1) + 3] += alpha * x[4 * (i + 1) + 3];
        } else {
            y[4 * i] += alpha * x[4 * i];
            y[4 * i + 1] += alpha * x[4 * i + 1];
            y[4 * i + 2] += alpha * x[4 * i + 2];
            y[4 * i + 3] += alpha * x[4 * i + 3];
        }
    }
}
