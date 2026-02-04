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
        c[i] = 0.0;
        for (j = 0; j <= 16; j++) {
            if (V3inv[i * 17 + j] != 0.0) {
                c[i] += V3inv[i * 17 + j] * fx[j * 2];
            }
        }
    }
}
