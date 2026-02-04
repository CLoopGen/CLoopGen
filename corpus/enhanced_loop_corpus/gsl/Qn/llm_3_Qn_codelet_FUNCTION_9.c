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
    int idx = i;
    if (left[idx] <= right[idx]) {
        int w = right[idx] - left[idx] + 1;
        weight[j] = w;
        jh = left[idx] + w / 2;
        ++j;
    }
}
}
