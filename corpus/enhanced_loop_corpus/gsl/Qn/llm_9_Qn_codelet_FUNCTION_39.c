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
for (i = 0; i < ni; ++i) {
    int stride = (i % 3) + 1;
    int jj;
    for (jj = left[i]; jj <= right[i]; jj += stride) {
        j++;
        j++; // Double increment to increase arithmetic intensity
    }
}
}
