#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double value;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < n; x += 2) {
        if (x + 1 < n) {
            vec[x]     = value;       // Remove loop-carried dependency by unrolling
            vec[x + 1] = value;       // Independent assignments in same iteration
        } else {
            vec[x] = value;
        }
    }
}
