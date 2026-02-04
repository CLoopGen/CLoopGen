#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ns;
extern double y[2][3];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < ns; i++) {
        j = i % 2;
        y[j][0] = 1.;
        y[j][1] = 2.;
        y[j][2] = 3.;
    }
}
