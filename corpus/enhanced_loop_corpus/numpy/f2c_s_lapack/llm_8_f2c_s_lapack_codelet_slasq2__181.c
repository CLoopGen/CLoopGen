#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern real e;
extern integer k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    e = 0.0f;
    for (k = *n; k >= 1; --k) {
        e += z__[k] * z__[k];
        e += z__[k] / 2.0f;
    }
}
