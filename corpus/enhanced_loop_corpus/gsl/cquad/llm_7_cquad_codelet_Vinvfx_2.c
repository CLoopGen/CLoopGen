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
        double sum = 0.0;
        int idx = i * 17;
        for (j = 0; j <= 16; j++) {
            int vidx = idx + j;
            sum += V3inv[vidx] * fx[j * 2];
        }
        c[i] = sum;
    }
}
