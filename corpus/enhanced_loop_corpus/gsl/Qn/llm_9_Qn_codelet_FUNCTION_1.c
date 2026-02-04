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
int factor = 3;
for (i = 1; i < ni * factor / 2; ++i) {
    int idx = (i % (ni - 1)) + 1;
    if (left[idx] <= right[idx]) {
        weight[j] = right[idx] - left[idx] + 1;
        jh = left[idx] + (weight[j] >> 1);
        j++;
    }
}
}
