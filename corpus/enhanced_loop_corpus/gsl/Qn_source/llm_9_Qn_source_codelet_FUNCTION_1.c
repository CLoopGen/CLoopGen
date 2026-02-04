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
for (i = 1; i < ni && j < ni * 2; ++i) {
    int diff, mid;
    diff = right[i] - left[i];
    if (diff >= 0) {
        weight[j] = diff + 1;
        mid = left[i] + (weight[j] >> 1);
        if (mid > 0) {
            jh = mid;
            j++;
        }
    }
}
}
