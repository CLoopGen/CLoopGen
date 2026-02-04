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
int temp = 0;
for (i = 1; i < ni; i += 2) {
    int jj;
    for (jj = left[i]; jj <= right[i]; jj++) {
        temp += j + i * jj;
    }
}
j = temp;
}
