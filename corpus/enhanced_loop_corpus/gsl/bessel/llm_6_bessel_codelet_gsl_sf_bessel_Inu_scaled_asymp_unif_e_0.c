#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double t;
extern double tpow[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = t;
    for (i = 1; i < 16; i++) {
        tpow[i] = temp * tpow[i - 1];
        temp = tpow[i]; // Introduce WAW and RAW dependency: temp now carries value from previous iteration
    }
}
