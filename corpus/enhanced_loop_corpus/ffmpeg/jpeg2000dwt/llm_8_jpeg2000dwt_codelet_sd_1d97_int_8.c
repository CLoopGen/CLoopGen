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
    for (i = (i0 >> 2) - 4; i < (i1 >> 2) + 2; i += 2) {
        int idx1 = 2 * i;
        int idx2 = idx1 + 2;
        int sum = p[idx1] + p[idx2];
        int val = (103949LL * sum + (1 << 15)) >> 16;
        p[idx1 + 1] -= val;
        p[idx1 + 3] -= val;
    }
}
