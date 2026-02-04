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
    float temp_min = quant_min_err;
    int temp_index = index;
    float prev_val = val;

    for (i = 0; i < num; i++) {
        // Create artificial loop-carried dependency via temp_min and temp_index
        // This changes data flow: each iteration depends on the result of the previous
        float error = (prev_val - arr[i]) * (prev_val - arr[i]);
        if (error < temp_min) {
            temp_min = error;
            temp_index = i;
        }
        // Artificially propagate state — introduces WAW and RAW dependencies
        prev_val += 0.0001f; // dummy change to create intra-loop dependency
    }

    // Commit final results to global variables
    quant_min_err = temp_min;
    index = temp_index;
}
