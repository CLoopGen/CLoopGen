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
    int l_val = left[i];
    int r_val = right[i];
    if (l_val > r_val) continue;
    weight[j] = r_val - l_val + 1;
    jh = l_val + weight[j] / 2;
    ++j;
}
}
