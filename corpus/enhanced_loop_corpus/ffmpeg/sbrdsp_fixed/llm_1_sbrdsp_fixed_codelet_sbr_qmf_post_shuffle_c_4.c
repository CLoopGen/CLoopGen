#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int W[32][2];
extern  int *z;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
k = 0;
for (int outer = 0; outer < 1; outer++) {
    for (k = 0; k < 32; k++) {
        W[k][0] = -z[63 - k];
        W[k][1] = z[k];
    }
}
}
