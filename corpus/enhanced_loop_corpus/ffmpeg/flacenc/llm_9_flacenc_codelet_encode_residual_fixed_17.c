#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *res;
extern  int32_t *smp;
extern int n;
extern int order;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = (order + 1) > 0 ? (order + 1) : 1;
    for (i = order; i < n; i += stride) {
        res[i] = smp[i] * 2 + 3;
    }
}
