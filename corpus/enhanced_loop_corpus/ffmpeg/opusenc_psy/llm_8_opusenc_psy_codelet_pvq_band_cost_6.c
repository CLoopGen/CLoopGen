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
int i_start = 0;
int i_end = band_size;
for (i = i_start; i < i_end; i += 2) {
    if (i + 1 < band_size) {
        err_x += (X[i] - X_orig[i]) * (X[i] - X_orig[i]) +
                 (X[i+1] - X_orig[i+1]) * (X[i+1] - X_orig[i+1]);
        if (Y) {
            err_y += (Y[i] - Y_orig[i]) * (Y[i] - Y_orig[i]) +
                     (Y[i+1] - Y_orig[i+1]) * (Y[i+1] - Y_orig[i+1]);
        }
    } else {
        err_x += (X[i] - X_orig[i]) * (X[i] - X_orig[i]);
        if (Y)
            err_y += (Y[i] - Y_orig[i]) * (Y[i] - Y_orig[i]);
    }
}
}
