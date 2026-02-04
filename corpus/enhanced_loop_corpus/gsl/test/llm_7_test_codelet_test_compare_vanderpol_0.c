#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ns;
extern double y[11][2];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (ns > 0) {
        y[0][0] = 1.;
        y[0][1] = 0.;
        for (i = 1; i < ns; i++) {
            y[i][0] = y[i-1][0]; // Introduce WAW and RAW loop-carried dependency
            y[i][1] = y[i-1][1];
        }
    }
}
