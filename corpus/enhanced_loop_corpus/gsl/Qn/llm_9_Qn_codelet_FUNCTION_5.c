#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *right;
extern int *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count with increased per-iteration work using indirect indexing
    int limit = (ni + 3) / 4;  // Roughly one-fourth the iterations
    for (i = 0; i < limit; ++i) {
        int j1 = 4*i;
        int j2 = 4*i + 1;
        int j3 = 4*i + 2;
        int j4 = 4*i + 3;
        // Perform four assignments per iteration with bounds checking
        right[j1] = p[j1];
        if (j2 < ni) right[j2] = p[j2];
        if (j3 < ni) right[j3] = p[j3];
        if (j4 < ni) right[j4] = p[j4];
    }
}
