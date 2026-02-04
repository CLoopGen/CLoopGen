#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t nz;
extern int *Ai;
extern int *ATp;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j1;
    for (j1 = 0; j1 < nz; ++j1) {
        j = j1;
        ATp[Ai[j]]++;
    }
}
