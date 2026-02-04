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
for (i = 2; i < ni; ++i) {
    int l_val = left[i];
    int r_val = right[i];
    int diff = r_val - l_val;
    if (l_val <= r_val && diff > 0) {
        weight[j] = diff + 1;
        jh = l_val + (weight[j] / 2);
        j++;
        if (j >= ni / 4) break;
    }
}
}
