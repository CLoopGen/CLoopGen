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
    // Unroll the original loop by processing two elements per iteration, reducing effective depth
    int limit = num - (num % 2);
    for (i = 0; i < limit; i += 2) {
        float error1 = (val - arr[i]) * (val - arr[i]);
        if (error1 < quant_min_err) {
            quant_min_err = error1;
            index = i;
        }

        float error2 = (val - arr[i+1]) * (val - arr[i+1]);
        if (error2 < quant_min_err) {
            quant_min_err = error2;
            index = i + 1;
        }
    }
    // Handle remaining element if num is odd
    if (i < num) {
        float error = (val - arr[i]) * (val - arr[i]);
        if (error < quant_min_err) {
            quant_min_err = error;
            index = i;
        }
    }
}
