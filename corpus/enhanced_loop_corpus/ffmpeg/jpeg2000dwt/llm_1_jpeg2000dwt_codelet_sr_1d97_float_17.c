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
    int outer_end = (i1 >> 1) + 1;
    int mid = (outer_start + outer_end) / 2;
    for (i = outer_start; i < mid; i++)
        p[2 * i + 1] -= 0.882911086F * (p[2 * i] + p[2 * i + 2]);
    for (i = mid; i < outer_end; i++)
        p[2 * i + 1] -= 0.882911086F * (p[2 * i] + p[2 * i + 2]);
}
