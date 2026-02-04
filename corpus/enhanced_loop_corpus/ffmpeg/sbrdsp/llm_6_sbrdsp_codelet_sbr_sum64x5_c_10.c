#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT *z;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INTFLOAT temp[64];
    for (k = 0; k < 64; k++) {
        temp[k] = z[k] + z[k + 64] + z[k + 128] + z[k + 192] + z[k + 256];
    }
    for (k = 0; k < 64; k++) {
        z[k] = temp[k];
    }
}
