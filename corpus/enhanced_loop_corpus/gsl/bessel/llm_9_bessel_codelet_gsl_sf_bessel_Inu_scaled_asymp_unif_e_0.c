#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double t;
extern double tpow[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    tpow[1] = t * tpow[0];
    for (i = 2; i < 16; i++) {
        tpow[i] = t * t * tpow[i - 2];
    }
}
