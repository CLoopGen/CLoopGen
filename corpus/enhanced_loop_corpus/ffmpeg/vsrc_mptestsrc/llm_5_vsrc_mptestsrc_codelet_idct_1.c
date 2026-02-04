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
            double sum = 0.;
            for (k = 0; k < 8; k++) {
                if (!(i == j && k < 4)) {
                    sum += c[k * 8 + j] * src[8 * i + k];
                }
            }
            tmp[8 * i + j] = sum;
        }
    }
}
