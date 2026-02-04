#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int W[32][2];
extern  int *z;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 32; i++) {
    for (k = i; k <= i; k++) {
        W[k][0] = -z[63 - k];
        W[k][1] = z[k];
    }
}
}
