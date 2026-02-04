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
    int16_t temp_a1, temp_a2;
    for (i = 5; i > 0; i--) {
        int idx = 6 - i;
        tmp = f[0][idx] + (unsigned int)f[1][idx] + 4096;
        temp_a1 = tmp >> 13;
        tmp = f[0][idx] - (unsigned int)f[1][idx] + 4096;
        temp_a2 = tmp >> 13;
        a[idx] = temp_a1;
        a[5 + idx] = temp_a2;
    }
}
