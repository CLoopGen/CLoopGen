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
    int j;
    for (i = order; i < n; i++) {
        res[i] = 0;
        for (j = 0; j < order && i - j >= 0; j++) {
            res[i] += smp[i - j];
        }
        res[i] -= order * smp[i - order > 0 ? i - order : 0];
    }
}
