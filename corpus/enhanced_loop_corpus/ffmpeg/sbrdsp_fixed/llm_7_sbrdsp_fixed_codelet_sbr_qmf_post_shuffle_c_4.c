#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int W[32][2];
extern  int *z;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 32; k++) {
        W[k][0] = -z[63 - k];
        W[31 - k][1] = z[31 - k]; // Reversed store order introduces WAR/WAW dependencies; loop-carried dependence on index mapping
    }
}
