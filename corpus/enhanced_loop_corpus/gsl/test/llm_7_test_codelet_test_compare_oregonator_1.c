#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ns;
extern double y[2][3];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp0, temp1, temp2;
    for (i = 0; i < ns; i++) {
        temp0 = 1.0;
        temp1 = 2.0;
        temp2 = 3.0;
        y[i][0] = temp0;
        y[i][1] = temp1;
        y[i][2] = temp2;
    }
}
