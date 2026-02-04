#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (i = 1; i < n; i++) {
        int j = i;
        float max_val = vec[best];
        int candidate = best;

        // Unroll comparison over a window of up to 4 prior indices
        for (int k = 0; k < stride && j - k >= 1; k++) {
            if (vec[j - k] > max_val) {
                max_val = vec[j - k];
                candidate = j - k;
            }
        }

        if (candidate != best) {
            best = candidate;
        }
    }
}
