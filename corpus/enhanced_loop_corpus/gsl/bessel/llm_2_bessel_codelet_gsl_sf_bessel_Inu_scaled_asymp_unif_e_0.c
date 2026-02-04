#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double t;
extern double tpow[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse order, then fill gaps)
    for (i = 15; i >= 1; i -= 2) {
        tpow[i] = t * tpow[i - 1];
    }
    for (i = 14; i >= 2; i -= 2) {
        tpow[i] = t * tpow[i - 1];
    }
}
