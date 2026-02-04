#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern long double chVals[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long double temp1, temp2, temp3, temp4;
    for (i = 0; i < 16; i++) {
        temp1 = (long double)(i * 1.0) / (i + 1.0);
        temp2 = (long double)(i * 2.5) / (i + 2.0);
        temp3 = (long double)(i * 3.7) / (i + 3.0);
        temp4 = (long double)(i * 4.1) / (i + 4.0);
        chVals[4*i + 0] = temp1 - temp2 + temp3 - temp4;
        chVals[4*i + 1] = temp2 - temp3 + temp4 - temp1;
        chVals[4*i + 2] = temp3 - temp4 + temp1 - temp2;
        chVals[4*i + 3] = temp4 - temp1 + temp2 - temp3;
    }
}
