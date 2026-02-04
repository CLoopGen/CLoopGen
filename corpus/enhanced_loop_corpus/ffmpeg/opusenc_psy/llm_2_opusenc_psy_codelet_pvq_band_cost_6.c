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
for (i = 0; i < band_size; i += 2) {
    err_x += (X[i] - X_orig[i]) * (X[i] - X_orig[i]);
    if (i + 1 < band_size) {
        err_x += (X[i+1] - X_orig[i+1]) * (X[i+1] - X_orig[i+1]);
    }
    if (Y) {
        err_y += (Y[i] - Y_orig[i]) * (Y[i] - Y_orig[i]);
        if (i + 1 < band_size) {
            err_y += (Y[i+1] - Y_orig[i+1]) * (Y[i+1] - Y_orig[i+1]);
        }
    }
}
}
