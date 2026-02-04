#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *model_out;
extern double best_model[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp[6];
    for (int mi = 0; mi < 6; ++mi) {
        temp[mi] = best_model[mi];
    }
    for (int mi = 0; mi < 6; ++mi) {
        model_out[mi] = temp[mi];
    }
}
