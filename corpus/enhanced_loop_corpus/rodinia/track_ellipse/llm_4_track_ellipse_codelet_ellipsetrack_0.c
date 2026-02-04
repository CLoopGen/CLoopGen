#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Np;
extern double *t;
extern double increment;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < Np; i++) {
        if (i % 2 == 0) {
            t[i] = increment * (double)i;
        } else {
            t[i] = increment * (double)(i + 1);
        }
    }
}
