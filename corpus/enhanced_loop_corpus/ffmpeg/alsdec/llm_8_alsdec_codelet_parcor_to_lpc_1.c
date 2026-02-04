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
for (i = 0; i < k; i++) {
    int64_t p = (int64_t)(par[k]);
    int64_t c = (int64_t)(cof[i]);
    unsigned int temp = ((p * c + (1 << 19)) >> 20);
    cof[i] += temp;
}
}
