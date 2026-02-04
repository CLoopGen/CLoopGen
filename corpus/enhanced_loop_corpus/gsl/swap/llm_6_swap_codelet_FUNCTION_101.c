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
    size_t temp_nz = nz;
    for (i = 0; i < temp_nz; ++i) {
        int index = Aj[i];
        ATp[index] = ATp[index] + 1;
    }
}
