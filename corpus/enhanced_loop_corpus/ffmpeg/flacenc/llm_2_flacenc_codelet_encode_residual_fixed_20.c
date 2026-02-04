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
extern int c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = order; i < n; i += 2) {
    int idx1 = i;
    int idx2 = i + 1;
    int b = smp[idx1] - smp[idx1 - 1];
    int d = b - a;
    res[idx1] = d - c;
    a = smp[idx2] - smp[idx1];
    c = a - b;
    res[idx2] = c - d;
}
}
