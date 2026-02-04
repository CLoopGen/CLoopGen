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
    float temp_quant_min_err = quant_min_err;
    int temp_index = index;
    for (i = 0; i < num; i++) {
        float diff = val - arr[i];
        float error = diff * diff;
        if (error < temp_quant_min_err) {
            temp_quant_min_err = error;
            temp_index = i;
        }
    }
    quant_min_err = temp_quant_min_err;
    index = temp_index;
}
