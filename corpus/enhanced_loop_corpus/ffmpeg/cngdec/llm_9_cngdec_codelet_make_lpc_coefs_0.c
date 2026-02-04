#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *refl;
extern int order;
extern float *next;
extern float *cur;
extern int m;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = 1; m < order; m++) {
    next[m] = refl[m] * cur[0];
    for (i = 0; i < m; i++) {
        next[i] = cur[i] - refl[m] * cur[m - i - 1] + refl[m] * refl[m];
    }
    float *SWAP_tmp = cur;
    cur = next;
    next = SWAP_tmp;
}
}
