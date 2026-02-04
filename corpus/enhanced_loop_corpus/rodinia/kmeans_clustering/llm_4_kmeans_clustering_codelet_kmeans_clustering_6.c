#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nclusters;
extern int i;
extern int nthreads;
extern float ***partial_new_centers;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nthreads <= 1) return;
    for (i = 1; i < nthreads; i++) {
        partial_new_centers[i] = partial_new_centers[i - 1] + nclusters;
    }
}
