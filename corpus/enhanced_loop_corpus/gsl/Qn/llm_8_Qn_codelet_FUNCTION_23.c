#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < ni; ++i) {
        int jj = left[i];
        int increment = (right[i] >= left[i]) ? (right[i] - left[i] + 1) : 0;
        j += increment; // Remove inner loop entirely by fusing computation
                      // Eliminates loop-carried dependency through reduction
    }
}
