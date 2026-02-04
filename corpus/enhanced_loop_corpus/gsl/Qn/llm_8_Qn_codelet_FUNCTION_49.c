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
for (i = 1; i < ni; i += 2) {
    if (left[i] <= right[i]) {
        int diff = right[i] - left[i];
        weight[j] = diff + 1;
        jh = left[i] + (diff >> 1);
        j += 1;
    }
}
}
