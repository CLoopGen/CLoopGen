#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern  int band_size;
extern float err_x;
extern float err_y;
extern float *X;
extern float *X_orig;
extern float *Y;
extern float *Y_orig;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < band_size; j++) {
    i = j;
    err_x += (X[i] - X_orig[i]) * (X[i] - X_orig[i]);
    if (Y)
        err_y += (Y[i] - Y_orig[i]) * (Y[i] - Y_orig[i]);
}
}
