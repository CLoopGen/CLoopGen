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
    for (i = 5; i > 0; i--) {
        int index = 6 - i;
        if (f[0][index] >= 0) {
            tmp = f[0][index] + (unsigned int)f[1][index] + 4096;
            a[index] = tmp >> 13;
        }
        if (f[1][index] < 1000) {
            tmp = f[0][index] - (unsigned int)f[1][index] + 4096;
            a[5 + i] = tmp >> 13;
        }
    }
}
