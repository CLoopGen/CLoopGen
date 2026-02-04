#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *rj;
extern double *rh;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 25; i += 4) {
        rj[i] *= -1;
        rh[i] *= -1;
        i += 1; // Simulate step of 2 by manually adjusting within loop
    }
}
