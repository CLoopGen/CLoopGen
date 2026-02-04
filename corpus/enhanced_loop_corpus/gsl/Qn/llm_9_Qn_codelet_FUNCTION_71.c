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
    for (i = 0; i < ni * 2; i++) {
        if (i >= 1 && i < ni) {
            int jj = left[i];
            j += (right[i] - jj + 1); // Replace inner loop with direct computation
        }
    }
}
