#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int i;
extern double best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < n; i++) {
        if (i % 2 == 1 && i + 1 < n) {
            if (vec[i] > best)
                best = vec[i];
            if (vec[i+1] > best)
                best = vec[i+1];
        }
        else if (i % 2 == 0) {
            if (vec[i] > best)
                best = vec[i];
        }
    }
}
