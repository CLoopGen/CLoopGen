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
    float local_val = val;
    float local_quant_min_err = quant_min_err;
    int local_index = index;
    for (i = 0; i < num; i += 2) {
        float error1 = (local_val - arr[i]) * (local_val - arr[i]);
        if (error1 < local_quant_min_err) {
            local_quant_min_err = error1;
            local_index = i;
        }
        if (i + 1 < num) {
            float error2 = (local_val - arr[i + 1]) * (local_val - arr[i + 1]);
            if (error2 < local_quant_min_err) {
                local_quant_min_err = error2;
                local_index = i + 1;
            }
        }
    }
    quant_min_err = local_quant_min_err;
    index = local_index;
}
