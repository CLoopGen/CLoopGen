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
    // Variant 1: Increased loop nesting depth by adding an outer loop that runs once (dummy loop)
    for (int dummy = 0; dummy < 1; dummy++) {
        for (k = lo; k <= hi; k++) {
            tmp = A_me[k][i];
            A_me[k][i] = A_me[k][j];
            A_me[k][j] = tmp;
        }
    }
}
