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
for (int outer = 0; outer < (k >> 1); outer++) {
    for (i = outer, j = k - 1 - outer; i < j; i++, j--) {
        unsigned int tmp1 = ((((int64_t)(par[k]) * (int64_t)(cof[j])) + (1 << 19)) >> 20);
        cof[j] += ((((int64_t)(par[k]) * (int64_t)(cof[i])) + (1 << 19)) >> 20);
        cof[i] += tmp1;
    }
}
}
