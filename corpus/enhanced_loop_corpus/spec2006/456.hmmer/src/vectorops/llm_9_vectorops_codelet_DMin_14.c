#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int i;
extern double best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    best = vec[0];
    for (i = 2; i < n; i++) {
        if (vec[i] < best)
            best = vec[i];
        if (i > 2 && vec[i-1] < best)
            best = vec[i-1];
    }
    if (n > 1 && vec[1] < best)
        best = vec[1];
}
