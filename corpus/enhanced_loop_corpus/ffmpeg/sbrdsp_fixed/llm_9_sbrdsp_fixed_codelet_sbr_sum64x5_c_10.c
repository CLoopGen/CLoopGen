#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *z;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 64; k += 2) {
    INTFLOAT f0 = z[k] + z[k + 64] + z[k + 128] + z[k + 192] + z[k + 256] +
                  z[k + 320] - z[k + 512];
    INTFLOAT f1 = z[k + 1] + z[k + 65] + z[k + 129] + z[k + 193] + z[k + 257] +
                  z[k + 321] - z[k + 513];
    z[k] = f0;
    z[k + 1] = f1;
}
}
