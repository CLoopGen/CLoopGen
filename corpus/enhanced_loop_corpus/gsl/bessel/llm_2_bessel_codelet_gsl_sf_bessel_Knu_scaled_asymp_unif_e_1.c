#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double t;
extern double tpow[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse order, with adjusted loop bounds)
    for (i = 14; i >= 0; i -= 2) {
        if (i + 1 < 16) tpow[i + 1] = t * tpow[i];
    }
}
