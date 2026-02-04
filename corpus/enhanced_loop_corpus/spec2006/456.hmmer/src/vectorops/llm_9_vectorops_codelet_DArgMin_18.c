#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (i = 1; i < n; i++) {
        int j;
        double current_min = vec[best];
        int current_index = best;
        for (j = 1; j < stride && i + j < n; j++) {
            if (vec[i + j] < current_min) {
                current_min = vec[i + j];
                current_index = i + j;
            }
        }
        if (current_index != best) {
            best = current_index;
            i += stride - 1;
        }
    }
}
