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
    int temp[32];
    for (i = 0; i < 32; i++) {
        temp[i] = bitinv32[i];
        out[i] = tab[temp[i]];
    }
}
