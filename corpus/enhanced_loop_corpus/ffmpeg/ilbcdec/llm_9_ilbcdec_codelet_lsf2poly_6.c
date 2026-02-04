#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t f[2][6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 5; i > 0; i -= 2) {
    f[0][i] += (unsigned int)f[0][i - 1];
    f[1][i] -= (unsigned int)f[1][i - 1];
    if (i > 1) {
        f[0][i-1] += (unsigned int)f[0][i - 2];
        f[1][i-1] -= (unsigned int)f[1][i - 2];
    }
}
}
