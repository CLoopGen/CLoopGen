#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT *z;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 64; k++) {
        INTFLOAT f = z[k] + z[k + 64];
        if (k < 32) {
            f += z[k + 128] + z[k + 192];
        } else {
            f += z[k + 256];
        }
        z[k] = f;
    }
}
