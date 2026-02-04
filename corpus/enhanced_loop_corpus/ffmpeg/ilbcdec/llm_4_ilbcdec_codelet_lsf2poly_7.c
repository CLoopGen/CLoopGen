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
        if (i % 2 == 1) {
            tmp = f[0][6 - i] + (unsigned int)f[1][6 - i] + 4096;
            a[6 - i] = tmp >> 13;
        }
        if (i % 2 == 0) {
            tmp = f[0][6 - i] - (unsigned int)f[1][6 - i] + 4096;
            a[5 + i] = tmp >> 13;
        }
    }
}
