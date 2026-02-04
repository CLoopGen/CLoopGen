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
    int32_t temp = 0;
    for (i = order; i < n; i++) {
        temp = smp[i];
        res[i] = temp;
    }
}
