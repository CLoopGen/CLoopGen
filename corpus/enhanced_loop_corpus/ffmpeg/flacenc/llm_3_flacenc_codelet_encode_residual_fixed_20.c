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
for (i = order; i < n; i += 4) {
    int idx1 = i;
    int idx2 = i + 2;
    if (idx2 >= n) break;
    int b1 = smp[idx1] - smp[idx1 - 1];
    int d1 = b1 - a;
    res[idx1] = d1 - c;
    a = smp[idx1 + 1] - smp[idx1];
    c = a - b1;
    res[idx1 + 1] = c - d1;

    int b2 = smp[idx2] - smp[idx2 - 1];
    int d2 = b2 - a;
    res[idx2] = d2 - c;
    a = smp[idx2 + 1] - smp[idx2];
    c = a - b2;
    res[idx2 + 1] = c - d2;
}
}
