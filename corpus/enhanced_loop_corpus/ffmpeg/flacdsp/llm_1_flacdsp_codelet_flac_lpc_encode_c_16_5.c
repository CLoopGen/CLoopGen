#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *res;
extern  int32_t *smp;
extern int order;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer = order / 2 + 1;
    int idx = 0;
    for (i = 0; i < outer; i++) {
        if (idx < order) res[idx] = smp[idx];
        idx++;
        if (idx < order) res[idx] = smp[idx];
        idx++;
    }
}
