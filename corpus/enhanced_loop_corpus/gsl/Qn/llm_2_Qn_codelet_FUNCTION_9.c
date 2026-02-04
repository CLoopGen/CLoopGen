#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int *weight;
extern int i;
extern int j;
extern int jh;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < ni; ++i) {
    int li = left[i];
    int ri = right[i];
    if (li <= ri) {
        weight[j] = ri - li + 1;
        jh = li + weight[j] / 2;
        ++j;
    }
}
}
