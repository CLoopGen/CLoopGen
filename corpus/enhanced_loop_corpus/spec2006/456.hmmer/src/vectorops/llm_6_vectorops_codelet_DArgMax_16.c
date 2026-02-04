#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int i;
extern int best;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp_best = best;
    for (i = 1; i < n; i++) {
        if (vec[i] > vec[temp_best]) {
            temp_best = i;
        }
    }
    best = temp_best;
}
