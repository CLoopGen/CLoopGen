#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int k;
extern  int32_t *par;
extern int32_t *cof;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0 , j = k - 1; i < j; i++ , j--) {
    int32_t* idx_i = &cof[par[i] % (k+1)];
    int32_t* idx_j = &cof[par[j] % (k+1)];
    unsigned int tmp1 = ((((int64_t)(par[k]) * (int64_t)(*idx_j)) + (1 << 19)) >> 20);
    *idx_j += ((((int64_t)(par[k]) * (int64_t)(*idx_i)) + (1 << 19)) >> 20);
    *idx_i += tmp1;
}
}
