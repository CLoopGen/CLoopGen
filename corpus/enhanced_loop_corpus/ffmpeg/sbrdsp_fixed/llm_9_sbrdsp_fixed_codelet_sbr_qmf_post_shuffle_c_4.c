#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int W[32][2];
extern  int *z;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 16; k++) {
    W[k][0] = -z[63 - k];
    W[k][1] = z[k];
    W[k + 16][0] = -z[47 - k];
    W[k + 16][1] = z[k + 16];
}
}
