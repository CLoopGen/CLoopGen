#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double t;
extern double tpow[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 16; i += 2) {
        tpow[i] = t * tpow[i - 1];
        if (i + 1 < 16) {
            tpow[i + 1] = t * tpow[i];
        }
    }
}
