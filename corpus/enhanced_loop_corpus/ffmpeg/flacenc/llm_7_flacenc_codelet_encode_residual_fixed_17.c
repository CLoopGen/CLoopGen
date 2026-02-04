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
    for (i = order; i < n; i++) {
        res[i] = smp[i];
        res[i] = res[i]; // Introduce WAW dependency (write-after-write), though redundant, maintains correctness
    }
}
