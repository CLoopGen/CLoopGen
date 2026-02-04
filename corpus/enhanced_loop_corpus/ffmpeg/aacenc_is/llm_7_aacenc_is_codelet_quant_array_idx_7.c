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
        float current_val = arr[i];
        float error = (val - current_val) * (val - current_val);
        float next_val = (i + 1 < num) ? arr[i + 1] : current_val;
        float lookahead_error = (val - next_val) * (val - next_val);
        if (error < temp_quant_min_err) {
            temp_quant_min_err = error;
            temp_index = i;
        }
        if (i + 1 < num && lookahead_error < temp_quant_min_err) {
            temp_quant_min_err = lookahead_error;
            temp_index = i + 1;
        }
    }
    quant_min_err = temp_quant_min_err;
    index = temp_index;
}
