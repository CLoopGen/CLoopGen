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
int k;
for (k = 1; k < ni; ++k) {
    int i = k;
    int diff = right[i] - left[i] + 1;
    int jj;
    for (jj = 0; jj < diff; ++jj) {
        j++;
    }
}
}
