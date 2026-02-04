#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double t;
extern double tpow[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array (simulates irregular access pattern)
    int indices[15];
    for (int j = 0; j < 15; j++) {
        indices[j] = 15 - j;  // Reverse index order: 15,14,...,1
    }
    for (i = 0; i < 15; i++) {
        int idx = indices[i];
        tpow[idx] = t * tpow[idx - 1];
    }
}
