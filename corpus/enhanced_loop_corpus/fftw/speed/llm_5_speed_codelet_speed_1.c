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
    for (k = 0; k < time_repeat; ++k) {
        if (k % 2 == 0) {
            t[k] /= iter;
        } else {
            t[k] *= 1.0; // No-op to maintain floating-point consistency
        }
    }
}
