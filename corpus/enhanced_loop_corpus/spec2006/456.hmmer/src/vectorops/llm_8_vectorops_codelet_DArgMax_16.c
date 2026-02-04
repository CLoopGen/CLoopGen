#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 1; i < n; i += 2) {
        if (i + 1 < n) {
            if (vec[i] > vec[best]) best = i;
            if (vec[i+1] > vec[best]) best = i+1;
        } else {
            if (vec[i] > vec[best]) best = i;
        }
    }
}
