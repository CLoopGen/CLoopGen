#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix_param;
extern int stride;
extern int i;
extern int j;
extern double maxcoef;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev = 1.0;
    for (i = 0; i < 64; i++)
        for (j = 0; j < 64; j++) {
            int idx = stride * i + j;
            double current = matrix_param[idx];
            matrix_param[idx] = (current / maxcoef) + prev;
            prev = current / maxcoef;
        }
}
