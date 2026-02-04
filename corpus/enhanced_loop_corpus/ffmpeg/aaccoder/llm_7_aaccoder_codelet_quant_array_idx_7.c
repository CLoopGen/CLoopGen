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
    // Introduce loop-carried dependency with staggered comparison
    // Each iteration depends on the previous iteration's result (WAW + RAW chain)
    for (i = 0; i < num; i++) {
        float error = (val - arr[i]) * (val - arr[i]);
        // Create sequential dependency: current decision depends on updated temp values
        if (error < temp_err) {
            temp_err = error;
            temp_index = i;
        }
        // Force update of global state each iteration (intentional WAW hazard introduced)
        // This creates a loop-carried dependence on global variables
        quant_min_err = temp_err;
        index = temp_index;
    }
    // Final value naturally remains in globals due to last-write semantics
}
