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
for (i = 2; i < ni; i += 2) {
    int jj;
    if (left[i] <= right[i]) {
        j += (right[i] - left[i] + 1);
    }
}
}
