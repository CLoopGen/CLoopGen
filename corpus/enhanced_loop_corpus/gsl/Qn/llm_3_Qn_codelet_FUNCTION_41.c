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
int stride = 2;
int limit = (ni % stride == 0) ? ni : ni - ni % stride;
for (i = stride; i < limit; i += stride) {
    if (left[i-1] <= right[i-1]) {
        weight[j] = right[i-1] - left[i-1] + 1;
        jh = left[i-1] + weight[j] / 2;
        ++j;
    }
}
}
