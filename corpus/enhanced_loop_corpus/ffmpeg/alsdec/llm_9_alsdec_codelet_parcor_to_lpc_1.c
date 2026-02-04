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
for (i = 0, j = k - 1; i <= j; i++, j--) {
    int64_t par_k = (int64_t)(par[k]);
    unsigned int tmp_i = ((par_k * (int64_t)(cof[i]) + (1 << 19)) >> 20);
    unsigned int tmp_j = ((par_k * (int64_t)(cof[j]) + (1 << 19)) >> 20);
    
    if (i != j) {
        cof[j] += tmp_i;
        cof[i] += tmp_j;
    } else {
        cof[i] += tmp_i;
    }
}
}
