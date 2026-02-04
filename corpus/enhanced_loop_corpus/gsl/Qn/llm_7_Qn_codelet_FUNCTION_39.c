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
    int prev_i = 0;
    for (i = 1; i < ni; ++i) {
        int jj;
        for (jj = left[prev_i] + left[i]; jj <= right[prev_i] + right[i]; ++jj) {
            j++;
        }
        prev_i = i;
    }
}
