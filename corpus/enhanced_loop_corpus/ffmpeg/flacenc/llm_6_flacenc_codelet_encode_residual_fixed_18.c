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
    int32_t prev = smp[order - 1];
    for (i = order; i < n; i++) {
        int32_t current = smp[i];
        res[i] = current - prev;
        prev = current;
    }
}
