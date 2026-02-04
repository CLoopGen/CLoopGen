#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int W[32][2];
extern  int *z;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[32][2];
    for (k = 0; k < 32; k++) {
        temp[k][0] = -z[63 - k];
        temp[k][1] = z[k];
    }
    for (k = 0; k < 32; k++) {
        W[k][0] = temp[k][0];
        W[k][1] = temp[k][1];
    }
}
