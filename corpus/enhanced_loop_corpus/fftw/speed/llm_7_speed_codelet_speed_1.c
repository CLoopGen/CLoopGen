#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int time_repeat;
extern double *t;
extern int iter;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (time_repeat > 0)
        t[0] /= iter;
    for (k = 1; k < time_repeat; ++k)
        t[k] /= t[k-1];
}
