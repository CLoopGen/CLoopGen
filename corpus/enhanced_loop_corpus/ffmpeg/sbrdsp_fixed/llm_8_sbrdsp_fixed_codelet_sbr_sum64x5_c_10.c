#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *z;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 32; k++) {
    INTFLOAT f1 = z[k] + z[k + 64] + z[k + 128];
    INTFLOAT f2 = z[k + 32] + z[k + 96] + z[k + 160];
    z[k] = f1;
    z[k + 32] = f2;
}
}
