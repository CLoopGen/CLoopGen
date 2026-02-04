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
for (i = 2; i < ni; i += 2) {  // Reduced trip count by iterating every second element
    int jj = left[i];
    if (jj <= right[i]) {
        j += (right[i] - jj + 1);  // Replace inner loop with direct computation
    }
}
}
