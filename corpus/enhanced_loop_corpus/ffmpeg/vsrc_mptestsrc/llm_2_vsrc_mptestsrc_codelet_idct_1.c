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
        int base_c = j;
        int base_src = 8 * i;
        for (k = 0; k < 8; k++) {
            sum += c[base_c + k * 8] * src[base_src + k];
        }
        tmp[8 * i + j] = sum;
    }
}
}
