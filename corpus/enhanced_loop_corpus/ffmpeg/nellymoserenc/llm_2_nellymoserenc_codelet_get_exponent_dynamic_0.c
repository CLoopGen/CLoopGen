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
for (i = 0; i < ((1 << 15) + 3000); i += 4) {
    if (best_val > opt[band][i]) {
        best_val = opt[band][i];
        best_idx = i;
    }
    if (i + 1 < ((1 << 15) + 3000) && best_val > opt[band][i + 1]) {
        best_val = opt[band][i + 1];
        best_idx = i + 1;
    }
    if (i + 2 < ((1 << 15) + 3000) && best_val > opt[band][i + 2]) {
        best_val = opt[band][i + 2];
        best_idx = i + 2;
    }
    if (i + 3 < ((1 << 15) + 3000) && best_val > opt[band][i + 3]) {
        best_val = opt[band][i + 3];
        best_idx = i + 3;
    }
}
}
