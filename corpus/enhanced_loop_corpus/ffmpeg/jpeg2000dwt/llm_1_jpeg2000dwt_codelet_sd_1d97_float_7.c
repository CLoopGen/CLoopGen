#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = (i0 >> 1); i < (i1 >> 1); i++) {
    int k = 2 * i;
    p[k] += 0.44350600000000001 * (p[k - 1] + p[k + 1]);
}
}
