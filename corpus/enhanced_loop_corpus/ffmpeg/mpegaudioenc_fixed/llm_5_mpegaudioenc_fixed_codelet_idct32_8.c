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
    for (i = 0; i < 32; i++) {
        int index = bitinv32[i];
        if (index < 16) {
            out[i] = tab[index] + 1;
        } else {
            out[i] = tab[index] - 1;
        }
    }
}
