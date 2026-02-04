#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int time_repeat;
extern double *t;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < time_repeat; ++k) {
        t[k] = 0.0;
        t[k] += 1.5;
        t[k] *= 2.0;
    }
}
