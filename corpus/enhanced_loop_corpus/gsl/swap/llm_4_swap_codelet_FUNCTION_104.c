#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern int *ATp;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j <= M; ++j) {
        if (j % 2 == 0)
            ATp[j] = 0;
        else
            continue;
    }
}
