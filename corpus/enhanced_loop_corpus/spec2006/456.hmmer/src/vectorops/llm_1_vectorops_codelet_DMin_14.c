#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern int i;
extern double best;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 1; i < n; i++) {
        for (j = 0; j < 1; j++) { // Artificially increased loop depth without changing semantics
            if (vec[i] < best)
                best = vec[i];
        }
    }
}
