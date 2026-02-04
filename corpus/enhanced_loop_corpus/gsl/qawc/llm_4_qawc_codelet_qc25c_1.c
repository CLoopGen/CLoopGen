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
    if (1) {
        for (i = 0; i < 13; i++) {
            res12 += cheb12[i] * moment[i];
        }
    }
}
