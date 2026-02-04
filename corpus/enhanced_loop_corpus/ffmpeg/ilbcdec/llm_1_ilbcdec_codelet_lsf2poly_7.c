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
    for (int k = 1; k <= 5; k++) { // Changed loop structure: reversed logic with incremented counter
        i = 6 - k; // Derived original index
        tmp = f[0][k] + (unsigned int)f[1][k] + 4096;
        a[k] = tmp >> 13;
        tmp = f[0][k] - (unsigned int)f[1][k] + 4096;
        a[11 - k] = tmp >> 13; // Maintains mapping: 5+i when i=5-k → 5+(6-k) = 11-k
    }
}
