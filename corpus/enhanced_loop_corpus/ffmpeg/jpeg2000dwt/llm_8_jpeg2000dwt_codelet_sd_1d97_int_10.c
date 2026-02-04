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
for (i = (i0 >> 2); i < (i1 >> 2); i++) {
    int idx = 4 * i;
    p[idx + 1] += (57862LL * (p[idx] + p[idx + 2]) + (1 << 15)) >> 16;
    p[idx + 3] += (57862LL * (p[idx + 2] + p[idx + 4]) + (1 << 15)) >> 16;
}
}
