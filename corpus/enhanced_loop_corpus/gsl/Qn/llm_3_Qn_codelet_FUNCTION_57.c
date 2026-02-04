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
int * restrict l_ptr = left;
int * restrict r_ptr = right;
int stride = 2;
for (i = 2; i < ni; i += stride) {
    int prev_i = i - 1;
    if (l_ptr[prev_i] <= r_ptr[prev_i]) {
        weight[j] = r_ptr[prev_i] - l_ptr[prev_i] + 1;
        jh = l_ptr[prev_i] + weight[j] / 2;
        ++j;
    }
}
}
