#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double V3inv[289];
extern  double *fx;
extern double *c;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 16; i++) {
        double sum = 0.;
        for (j = 0; j <= 8; j++) {
            sum += V3inv[i * 17 + (j << 1)] * fx[j << 1] +
                   ((i * 17 + (j << 1) + 1 < 289) ? V3inv[i * 17 + (j << 1) + 1] * fx[(j << 1) + 2] : 0.);
        }
        c[i] = sum;
    }
}
