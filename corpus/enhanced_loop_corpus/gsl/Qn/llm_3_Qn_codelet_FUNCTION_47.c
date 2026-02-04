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
    int *left_ptr = &left[i];
    int *right_ptr = &right[i];
    for (jj = *left_ptr; jj <= *right_ptr; ++jj) {
        j++;
    }
}
}
