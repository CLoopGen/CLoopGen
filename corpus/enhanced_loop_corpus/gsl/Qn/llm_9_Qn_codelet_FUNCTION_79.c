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
    for (i = 1; i < ni * 2; ++i) { // Doubled trip count
        int jj = left[i % ni];
        int limit = right[i % ni];
        if (jj <= limit) {
            j += (limit - jj + 1) * 2; // Replace inner loop with direct computation and amplify effect
        }
    }
}
