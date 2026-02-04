#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double cheb12[13];
extern double moment[25];
extern double res12;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 13; i += 2) {
        res12 += cheb12[i] * moment[i];
        if (i + 1 < 13) {
            res12 += cheb12[i + 1] * moment[i + 1];
        }
    }
}
