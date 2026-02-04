#include <stdio.h>

#include <inttypes.h>

extern float *vec;
extern int n;
extern int i;
extern float best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < n; i += 2) {
        if (i + 1 < n) {
            float val1 = vec[i];
            float val2 = vec[i + 1];
            if (val1 < best)
                best = val1;
            if (val2 < best)
                best = val2;
        } else {
            if (vec[i] < best)
                best = vec[i];
        }
    }
}
