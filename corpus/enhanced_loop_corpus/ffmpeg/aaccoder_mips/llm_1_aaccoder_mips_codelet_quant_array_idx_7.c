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
    if (num > 0) {
        i = 0;
        float error = (val - arr[i]) * (val - arr[i]);
        if (error < quant_min_err) {
            quant_min_err = error;
            index = i;
        }
    }
}
