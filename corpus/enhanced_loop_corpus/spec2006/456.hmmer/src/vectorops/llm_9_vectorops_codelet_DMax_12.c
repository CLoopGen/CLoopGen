#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int i;
extern double best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    best = vec[0];
    for (i = 1; i < n && i < 1000; i++) {
        double diff = vec[i] - best;
        if (diff > 0.0) {
            best = vec[i];
        }
    }
}
