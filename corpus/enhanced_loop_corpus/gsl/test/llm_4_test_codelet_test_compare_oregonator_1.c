#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ns;
extern double y[2][3];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ns; i++) {
        if (i >= 2) continue;
        y[i][0] = 1.;
        y[i][1] = 2.;
        y[i][2] = 3.;
    }
}
