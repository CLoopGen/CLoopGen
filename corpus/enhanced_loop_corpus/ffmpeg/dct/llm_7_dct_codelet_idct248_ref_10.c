#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double c8[8][8];
extern double block1[64];
extern double block2[64];
extern double sum;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double temp_sum[8];
for (i = 0; i < 8; i++) {
    for (k = 0; k < 8; k++) {
        double c_val = c8[k][0]; 
        for (j = 0; j < 8; j++) {
            temp_sum[j] = (k == 0) ? 0.0 : temp_sum[j];
            temp_sum[j] += c_val * block1[8 * i + k];
        }
    }
    for (j = 0; j < 8; j++) {
        block2[8 * i + j] = temp_sum[j];
    }
}
}
