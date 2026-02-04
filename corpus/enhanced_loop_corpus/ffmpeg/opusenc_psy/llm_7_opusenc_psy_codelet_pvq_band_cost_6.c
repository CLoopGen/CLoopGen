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
    float local_err_x = err_x;
    float local_err_y = err_y;
    for (i = 0; i < band_size; i++) {
        local_err_x += (X[i] - X_orig[i]) * (X[i] - X_orig[i]);
        if (Y)
            local_err_y += (Y[i] - Y_orig[i]) * (Y[i] - Y_orig[i]);
    }
    err_x = local_err_x;
    err_y = local_err_y;
}
