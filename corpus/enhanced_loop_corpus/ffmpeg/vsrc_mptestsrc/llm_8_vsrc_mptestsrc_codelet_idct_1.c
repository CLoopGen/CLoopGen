#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double c[64];
extern int src[64];
extern int i;
extern int j;
extern int k;
extern double tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
        double sum1 = 0., sum2 = 0.;
        for (k = 0; k < 4; k++) {
            sum1 += c[k * 8 + j] * src[8 * i + k];
            sum2 += c[(k + 4) * 8 + j] * src[8 * i + (k + 4)];
        }
        tmp[8 * i + j] = sum1 + sum2;
    }
}
}
