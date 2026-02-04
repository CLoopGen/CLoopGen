#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x_lp;
extern int len;
extern float x_lp4[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *temp = (float*)malloc((len >> 2) * sizeof(float));
    for (int j = 0; j < (len >> 2); j++) {
        temp[j] = x_lp[2 * j];
    }
    for (int j = 0; j < (len >> 2); j++) {
        x_lp4[j] = temp[j];
    }
    free(temp);
}
