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
for (i = 0; i < ni; i += 2) {
    if (i + 1 < ni && left[i] <= right[i]) {
        weight[j] = (right[i] - left[i] + 1) * 2;
        jh = left[i] + weight[j] / 4;
        ++j;
    }
    if (i + 1 < ni && left[i+1] <= right[i+1]) {
        weight[j] = (right[i+1] - left[i+1] + 1) * 2;
        jh = left[i+1] + weight[j] / 4;
        ++j;
    }
}
}
