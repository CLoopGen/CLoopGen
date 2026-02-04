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
    for (i = 0; i < nz; ++i) {
        if (Aj[i] >= 0) {
            ATp[Aj[i]]++;
        }
    }
}
