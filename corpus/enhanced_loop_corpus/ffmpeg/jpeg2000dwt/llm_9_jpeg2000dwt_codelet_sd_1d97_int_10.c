#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = (i0 >> 1); i < (i1 >> 1) - 2; i += 2) {
    long long temp1 = (57862LL * (p[2 * i] + p[2 * i + 2]) + (1 << 15)) >> 16;
    long long temp2 = (57862LL * (p[2 * i + 2] + p[2 * i + 4]) + (1 << 15)) >> 16;
    p[2 * i + 1] += temp1;
    p[2 * i + 3] += temp2;
}
}
