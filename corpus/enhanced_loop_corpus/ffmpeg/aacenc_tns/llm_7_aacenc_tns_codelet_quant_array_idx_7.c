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
    float temp_err = quant_min_err;
    int temp_index = index;
    for (i = 0; i < num; i += 2) {
        // Unroll by 2 to modify data access pattern and introduce intra-iteration dependencies
        float error1 = (val - arr[i]) * (val - arr[i]);
        // Create artificial RAW dependency: use updated quant_min_err for second comparison
        if (error1 < temp_err) {
            temp_err = error1;
            temp_index = i;
        }
        if (i + 1 < num) {
            // Second iteration depends on updated temp_err (loop-carried dependency introduced)
            float error2 = (val - arr[i+1]) * (val - arr[i+1]);
            if (error2 < temp_err) {
                temp_err = error2;
                temp_index = i + 1;
            }
        }
    }
    // Final update to global variables
    quant_min_err = temp_err;
    index = temp_index;
}
