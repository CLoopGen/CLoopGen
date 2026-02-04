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
        int jj;
        int step = (i % 2) + 1; // Vary stride based on i
        for (jj = left[i]; jj <= right[i]; jj += step) { // Modify effective trip count via variable step
            j++;
        }
    }
}
