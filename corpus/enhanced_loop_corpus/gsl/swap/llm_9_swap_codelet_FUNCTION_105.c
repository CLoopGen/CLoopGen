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
    for (j = 0; j < nz; j += 2) {
        if (j + 1 < nz) {
            ATp[Ai[j]]++;
            ATp[Ai[j + 1]]++;
        } else {
            ATp[Ai[j]]++;
        }
    }
}
