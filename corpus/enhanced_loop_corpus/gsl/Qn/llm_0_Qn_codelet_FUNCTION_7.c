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
int i = 1;
while (i < ni) {
    int jj = left[i];
    while (jj <= right[i]) {
        j++;
        jj++;
    }
    i++;
}
}
