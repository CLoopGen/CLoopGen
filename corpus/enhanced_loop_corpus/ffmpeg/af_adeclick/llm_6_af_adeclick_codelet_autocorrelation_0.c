#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *input;
extern int order;
extern int size;
extern double *output;
extern double scale;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_output[1024]; // Local accumulation to remove WAW and RAW across iterations
    for (i = 0; i <= order; i++) {
        double value = 0.;
        int offset = i;
        for (j = offset; j < size; j++) {
            value += input[j] * input[j - offset]; // Dependency on input with fixed offset
        }
        temp_output[i] = value * scale; // Store in local array to break output write dependency
    }
    // Finalize output writes without loop-carried dependencies
    for (i = 0; i <= order; i++) {
        output[i] = temp_output[i];
    }
}
