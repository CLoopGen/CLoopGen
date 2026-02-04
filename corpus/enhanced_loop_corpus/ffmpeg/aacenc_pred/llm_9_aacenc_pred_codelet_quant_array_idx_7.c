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
quant_min_err = (val - arr[0]) * (val - arr[0]);
index = 0;
for (i = 1; i < num; i++) {
    float diff = val - arr[i];
    float error = diff * diff;
    quant_min_err = (error < quant_min_err) ? error : quant_min_err;
    index = (error < quant_min_err) ? i : index;
}
}
