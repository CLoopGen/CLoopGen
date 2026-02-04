#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *v;
extern int len;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < len; k += 8) {
        // Variant 1: Consecutive memory access by reordering operations to access adjacent elements
        float temp1 = v[k + 2];
        float temp2 = v[k + 3];
        v[k + 2] = v[k + 4];
        v[k + 3] = v[k + 5];
        v[k + 4] = temp1;
        v[k + 5] = temp2;
    }
}
