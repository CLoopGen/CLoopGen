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
    float local_quant_min_err = quant_min_err;
    int local_index = index;

    for (i = 0; i < num; i++) {
        float diff = val - arr[i];
        float error = diff * diff;
        // Introduce a local accumulation to remove immediate write-write (WAW) and write-read (WAR) dependencies on shared globals
        // Only update local tracking variables; final update happens after loop
        if (error < local_quant_min_err) {
            local_quant_min_err = error;
            local_index = i;
        }
    }

    // Final write to global state outside the loop (eliminates loop-carried WAW/WAR on globals)
    quant_min_err = local_quant_min_err;
    index = local_index;
}
