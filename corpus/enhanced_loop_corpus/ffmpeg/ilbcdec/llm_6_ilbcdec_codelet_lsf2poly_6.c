#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t f[2][6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 5; i > 0; i--) {
        int32_t temp0 = f[0][i - 1];
        f[0][i] += (unsigned int)temp0;
        f[1][i] -= (unsigned int)f[1][i - 1];
    }
}
