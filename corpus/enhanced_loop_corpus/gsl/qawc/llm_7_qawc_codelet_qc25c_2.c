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
    res24 = 0.0;
    for (i = 0; i < 25; i += 2) {
        double prod1 = cheb24[i] * moment[i];
        res24 += prod1;
        if (i + 1 < 25) {
            double prod2 = cheb24[i + 1] * moment[i + 1];
            res24 += prod2;
        }
    }
}
