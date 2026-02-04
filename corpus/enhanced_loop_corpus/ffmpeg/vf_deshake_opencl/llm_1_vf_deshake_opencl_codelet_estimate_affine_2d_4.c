#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *model_out;
extern double best_model[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int mi = 0; mi < 2; ++mi) {
        for (int mj = 0; mj < 3; ++mj) {
            int idx = mi * 3 + mj;
            model_out[idx] = best_model[idx];
        }
    }
}
