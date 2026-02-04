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
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = order; i < n; i += 4) {
    if (i + 2 >= n) break;
    int b0 = smp[i] - smp[i - 1];
    int d0 = b0 - a;
    int f0 = d0 - c;
    res[i] = f0 - e;
    int a0 = smp[i + 1] - smp[i];
    int c0 = a0 - b0;
    int e0 = c0 - d0;
    res[i + 1] = e0 - f0;

    int b1 = smp[i + 2] - smp[i + 1];
    int d1 = b1 - a0;
    int f1 = d1 - c0;
    res[i + 2] = f1 - e0;
    a = smp[i + 3] - smp[i + 2];
    c = a - b1;
    e = c - d1;
    res[i + 3] = e - f1;
}
}
