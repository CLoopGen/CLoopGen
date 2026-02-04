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
        int temp = j; // Introduce temporary to modify data dependency
        for (jj = left[i]; jj <= right[i]; ++jj) {
            temp++; // Remove direct WAW on 'j' inside inner loop
        }
        j = temp; // Write back once per outer iteration (eliminate loop-carried WAW on j)
    }
}
