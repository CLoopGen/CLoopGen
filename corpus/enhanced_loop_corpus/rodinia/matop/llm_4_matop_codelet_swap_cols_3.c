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
    if (lo <= hi) {
        for (k = lo; k <= hi; k++) {
            tmp = A_me[i][k];
            A_me[i][k] = A_me[j][k];
            A_me[j][k] = tmp;
        }
    }
}
