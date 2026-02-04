#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t f[2][6];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 4; i > 0; i--) {
    f[0][i] += (unsigned int)f[0][i - 1];
    f[1][i] -= (unsigned int)f[1][i - 1];
    f[0][i] += (unsigned int)f[0][i + 1] / 2;
    f[1][i] -= (unsigned int)f[1][i + 1] / 2;
}
}
