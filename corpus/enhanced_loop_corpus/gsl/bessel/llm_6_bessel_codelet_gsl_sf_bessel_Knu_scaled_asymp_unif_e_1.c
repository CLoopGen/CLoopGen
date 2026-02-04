#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double t;
extern double tpow[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp[16];
    temp[0] = tpow[0];
    for (i = 1; i < 16; i++) {
        temp[i] = t * temp[i - 1];
    }
    for (i = 1; i < 16; i++) {
        tpow[i] = temp[i];
    }
}
