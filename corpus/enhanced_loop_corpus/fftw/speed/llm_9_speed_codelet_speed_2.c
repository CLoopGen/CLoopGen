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
    for (k = 0; k < time_repeat; ++k) {
        for (i = 0; i < 4; ++i) {
            t[k] += (double)(k + i) * 0.1;
        }
    }
}
