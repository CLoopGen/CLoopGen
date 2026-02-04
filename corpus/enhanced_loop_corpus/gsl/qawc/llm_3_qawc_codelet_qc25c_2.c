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
    // Variant 2: Reverse consecutive memory access – traverse arrays from last to first element
    size_t i;
    for (i = 24; ; i--) {
        res24 += cheb24[i] * moment[i];
        if (i == 0) break;
    }
}
