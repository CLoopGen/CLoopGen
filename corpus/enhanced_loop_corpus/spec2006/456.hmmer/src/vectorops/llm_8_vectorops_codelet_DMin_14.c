#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int i;
extern double best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            double val1 = vec[i];
            double val2 = vec[i + 1];
            if (val1 < best) best = val1;
            if (val2 < best) best = val2;
        } else {
            if (vec[i] < best) best = vec[i];
        }
    }
}
