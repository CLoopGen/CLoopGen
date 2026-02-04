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
    int left_val = left[i];
    int right_val = right[i];
    for (jj = left_val; jj <= right_val; jj += 2) {
        j++;
    }
}
}
