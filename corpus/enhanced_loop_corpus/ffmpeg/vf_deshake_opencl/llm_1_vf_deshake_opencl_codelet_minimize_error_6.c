#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *model_out;
extern double best_model[6];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth1 = 0; depth1 < 2; ++depth1) {
        for (int depth2 = 0; depth2 < 3; ++depth2) {
            int mi = depth1 * 3 + depth2;
            if (mi < 6) {
                model_out[mi] = best_model[mi];
            }
        }
    }
}
