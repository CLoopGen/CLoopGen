#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int bitinv32[32];
extern int *out;
extern int *tab;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 2) {
        out[i] = tab[bitinv32[i % 32]];
        out[i + 1] = tab[bitinv32[(i + 1) % 32]];
    }
}
