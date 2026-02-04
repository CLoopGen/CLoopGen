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
    for (i = 0; i < 25; i += 2) {
        if (i + 1 < 25) {
            res24 += cheb24[i] * moment[i] + cheb24[i+1] * moment[i+1];
        } else {
            res24 += cheb24[i] * moment[i];
        }
    }
}
