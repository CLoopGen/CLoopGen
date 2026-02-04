#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int i;
extern float best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < n; i++) {
        if (vec[i] < best) {
            best = vec[i];
        } else {
            // Introduce alternative control path (even if trivial)
            if (i % 2 == 0)
                continue;
        }
    }
}
