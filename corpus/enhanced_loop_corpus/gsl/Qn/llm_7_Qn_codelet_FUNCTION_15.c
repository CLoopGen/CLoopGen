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
        int offset = 0;
        for (jj = left[i]; jj <= right[i]; ++jj) {
            offset++; // Eliminate direct use of j, compute increment independently
        }
        j += offset; // Update j in a single operation, removing per-iteration RAW/WAR
    }
}
