#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int band;
extern int best_idx;
extern float best_val;
extern float (*opt)[35768];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_best_val = best_val;
    int local_best_idx = best_idx;
    int upper_bound = (1 << 15) + 3000;

    for (i = 0; i < upper_bound; i++) {
        float current_val = opt[band][i];
        if (local_best_val > current_val) {
            local_best_val = current_val;
            local_best_idx = i;
        }
    }

    best_val = local_best_val;
    best_idx = local_best_idx;
}
