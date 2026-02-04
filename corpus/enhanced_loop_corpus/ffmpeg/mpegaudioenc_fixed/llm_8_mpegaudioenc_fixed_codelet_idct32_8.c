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
        out[i/2] = tab[bitinv32[i/2]] + i;
    }
}
