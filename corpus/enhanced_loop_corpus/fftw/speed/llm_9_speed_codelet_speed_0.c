#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int time_repeat;
extern double *t;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (k = 0; k < time_repeat * 4; ++k) {
        for (i = 0; i < 3; ++i) {
            t[k % (1 << 16)] = (double)(k + i) * 0.1;
        }
    }
}
