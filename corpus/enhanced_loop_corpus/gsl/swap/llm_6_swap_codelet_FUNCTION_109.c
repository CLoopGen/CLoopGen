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
    size_t local_nz = nz;
    int* local_ATp = ATp;
    int* local_Aj = Aj;
    for (i = 0; i < local_nz; ++i) {
        size_t index = local_Aj[i];
        local_ATp[index] += 1;
    }
}
