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
    for (i = 31; i >= 0; i--) {
        int temp = bitinv32[i];
        out[i] = tab[temp] * temp + i;
    }
}
