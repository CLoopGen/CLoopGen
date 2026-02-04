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
for (m = 0; m < order; m++) {
    next[m] = refl[m];
    for (i = 0; i < m; i += 2) {
        if (i + 1 < m) {
            next[i]     = cur[i] + refl[m] * cur[m - i - 1];
            next[i + 1] = cur[i + 1] - refl[m] * cur[m - i - 2];
        } else {
            next[i] = cur[i] + refl[m] * cur[m - i - 1];
        }
    }
    float *SWAP_tmp = cur;
    cur = next;
    next = SWAP_tmp;
}
}
