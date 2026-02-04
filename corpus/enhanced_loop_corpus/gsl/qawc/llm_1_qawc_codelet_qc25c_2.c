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
    for (size_t outer = 0; outer < 5; outer++) {
        for (size_t inner = 0; inner < 5; inner++) {
            i = outer * 5 + inner;
            if (i < 25) {
                res24 += cheb24[i] * moment[i];
            }
        }
    }
}
