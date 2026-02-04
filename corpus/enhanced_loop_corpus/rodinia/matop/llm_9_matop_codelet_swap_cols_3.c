#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int j;
extern int lo;
extern int hi;
extern int k;
extern double **A_me;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count with conditional skip pattern and minimal arithmetic overhead
    // Iterates only over even indices, reducing total iterations by ~50%
    int k;
    for (k = lo; k <= hi; k += 2) {
        // Simple swap without any extra operations
        tmp = A_me[i][k];
        A_me[i][k] = A_me[j][k];
        A_me[j][k] = tmp;
    }
}
