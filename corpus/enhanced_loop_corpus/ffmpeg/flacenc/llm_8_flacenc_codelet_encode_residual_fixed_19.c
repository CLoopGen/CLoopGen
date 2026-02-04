#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *res;
extern  int32_t *smp;
extern int n;
extern int order;
extern int i;
extern int a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = order; i < n; i++) {
        int b = smp[i] - smp[i - 1];
        res[i] = (b - a) * 2 + 1;
        a = smp[i] - smp[i - 2 < 0 ? i - 1 : i - 2]; 
    }
}
