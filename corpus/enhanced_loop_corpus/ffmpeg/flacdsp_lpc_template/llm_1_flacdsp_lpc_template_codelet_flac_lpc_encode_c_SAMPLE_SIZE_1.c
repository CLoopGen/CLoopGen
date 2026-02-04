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
    if (order > 0) {
        i = 0;
        for (; i < order; ) {
            res[i] = smp[i];
            i++;
        }
    }
}
