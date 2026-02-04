#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double V1inv[25];
extern  double *fx;
extern double *c;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 4; i++) {
        double sum = 0.0;
        for (j = 0; j <= 4; j++) {
            sum += V1inv[i * 5 + j] * fx[j * 8];
        }
        c[i] = sum;
        if (i > 0) {
            c[i] += c[i - 1] * 0.0001; // Introduce artificial WAW and loop-carried dependency (very small coupling)
        }
    }
}
