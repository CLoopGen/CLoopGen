#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double cheb24[25];
extern double moment[25];
extern double res24;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp1 = 0.0, temp2 = 0.0, temp3 = 0.0;
    for (i = 0; i < 24; i += 3) {
        temp1 += cheb24[i] * moment[i];
        temp2 += cheb24[i+1] * moment[i+1];
        temp3 += cheb24[i+2] * moment[i+2];
    }
    res24 += temp1 + temp2 + temp3;
    // Handle leftover element if any (when i reaches 24)
    if (i == 24) {
        res24 += cheb24[24] * moment[24];
    }
}
