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
for (i = 0; i < ni; ++i) {
    int diff, mid;
    if (left[i] <= right[i]) {
        diff = right[i] - left[i];
        weight[j] = diff + 1;
        mid = left[i] + (diff >> 1);
        jh = mid + (weight[j] & 1);
        j += 1;
    }
}
}
