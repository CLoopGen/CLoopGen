#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int *refl;
extern int *b1;
extern int *b2;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 2;
int n = 10;
for (i = 0; i < n; i += stride) {
    int idx = i;
    if (idx < n) {
        b1[idx] = refl[idx] * 16;
        for (j = 0; j < idx; j++) {
            int access_idx = idx - j - 1;
            b1[j] = ((int)(refl[idx] * (unsigned int)b2[access_idx]) >> 12) + b2[j];
        }
    }
    int *SWAP_tmp = b1;
    b1 = b2;
    b2 = SWAP_tmp;
}
}
