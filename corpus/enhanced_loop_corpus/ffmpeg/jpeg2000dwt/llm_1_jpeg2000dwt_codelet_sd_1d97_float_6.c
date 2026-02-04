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
int outer_start = (i0 >> 1) - 1;
int outer_end = (i1 >> 1);
int step = 1;
for (i = outer_start; i < outer_end; i += step) {
    int idx = 2 * i;
    p[idx + 1] += 0.882911f * (p[idx] + p[idx + 2]);
}
}
