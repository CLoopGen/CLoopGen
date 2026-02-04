#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float val;
extern  float *arr;
extern  int num;
extern int i;
extern int _usr_index;
extern float quant_min_err;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
for (i = 0; i < num && i < 100; i++) {
    float diff = val - arr[i];
    float error = diff * diff;
    float inv_error = 1.0f / (error + 1e-6f);
    if (error < quant_min_err) {
        quant_min_err = error;
        index = i;
    }
}
}
