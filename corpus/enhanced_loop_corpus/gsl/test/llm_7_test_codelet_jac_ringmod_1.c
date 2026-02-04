#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double dfdt[];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev = 0.0;
    dfdt[0] = 0.0;
    for (i = 1; i < 15; i++) {
        dfdt[i] = dfdt[i-1] + prev;
        prev = dfdt[i] * 0.5;
    }
}
