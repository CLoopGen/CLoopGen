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
    int outer_i;
    int step = 2;
    for (outer_i = (i0 >> 1) - 1; outer_i < (i1 >> 1) + 2; outer_i += step)
        for (i = outer_i; i < outer_i + step && i < (i1 >> 1) + 2; i++)
            p[2 * i] -= 0.443506867F * (p[2 * i - 1] + p[2 * i + 1]);
}
