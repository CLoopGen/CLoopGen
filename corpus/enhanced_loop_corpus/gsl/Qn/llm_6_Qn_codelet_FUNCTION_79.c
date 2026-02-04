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
        int temp = j; // Introduce temporary to remove direct WAW on j
        for (jj = left[i]; jj <= right[i]; ++jj) {
            temp++; // Modify local copy, removing loop-carried dependence on j
        }
        j = temp; // Only one write to j after inner loop
    }
}
