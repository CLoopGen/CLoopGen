#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *rj;
extern double *rh;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 25; i += 2) {
        if (i % 3 != 0) {
            rj[i] *= -1;
            rh[i] *= -1;
        }
    }
}
