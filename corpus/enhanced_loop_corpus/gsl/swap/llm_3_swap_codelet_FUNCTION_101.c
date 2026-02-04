#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t nz;
extern int *Aj;
extern int *ATp;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < nz; ++j) {
        size_t idx = Aj[nz - 1 - j]; // Reverse access pattern: indirect and reverse-indexed
        ATp[idx]++;
    }
}
