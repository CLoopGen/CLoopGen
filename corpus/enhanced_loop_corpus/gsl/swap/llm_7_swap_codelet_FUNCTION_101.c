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
    if (nz == 0) return;
    ATp[Aj[0]]++;
    for (i = 1; i < nz; ++i) {
        ATp[Aj[i]] += (Aj[i] != Aj[i-1]) ? 1 : 2;
    }
}
