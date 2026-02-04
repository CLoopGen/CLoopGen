#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT *z;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 128; k++) {
    INTFLOAT f = z[k] + z[k + 128] + z[k + 256] + z[k + 384];
    z[k] = f;
}
}
