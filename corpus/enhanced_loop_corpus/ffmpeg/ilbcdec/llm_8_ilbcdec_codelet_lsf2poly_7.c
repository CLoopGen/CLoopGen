#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *a;
extern int32_t f[2][6];
extern int32_t tmp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 4; i > 0; i--) {
    tmp = f[0][6 - i] + (unsigned int)f[1][6 - i] + 8192;
    a[6 - i] = tmp >> 14;
    tmp = f[0][6 - i] - (unsigned int)f[1][6 - i] + 8192;
    a[5 + i] = tmp >> 14;
}
}
