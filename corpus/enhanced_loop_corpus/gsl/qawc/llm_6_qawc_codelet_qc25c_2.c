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
    double temp_res24 = 0.0;
    for (i = 0; i < 25; i++) {
        temp_res24 += cheb24[i] * moment[i];
    }
    res24 += temp_res24;
}
