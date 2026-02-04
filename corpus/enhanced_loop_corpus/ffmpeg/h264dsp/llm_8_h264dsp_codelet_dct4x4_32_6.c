#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int i;
extern int32_t tmp[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    const int z0 = tmp[i * 2 + 0] + tmp[i * 2 + 1];
    const int z1 = tmp[i * 2 + 0] - tmp[i * 2 + 1];
    coef[i * 2 + 0] = z0;
    coef[i * 2 + 1] = z1;
}
}
