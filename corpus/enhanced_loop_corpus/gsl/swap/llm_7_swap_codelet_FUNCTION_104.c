#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern int *ATp;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 1; i <= M + 1; ++i) {
        ATp[i - 1] = 0;
        if (i > 1)
            ATp[i - 2] = ATp[i - 1]; // Introduce WAW and RAW dependency
    }
    j = M + 1;
}
