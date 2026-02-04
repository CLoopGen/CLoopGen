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
    for (k = *n; k >= 1; --k) {
        if (k % 2 == 1) {
            e += z__[k];
        }
    }
    for (k = *n; k >= 1; --k) {
        if (k % 2 == 0) {
            e -= z__[k] * 0.5f;
        }
    }
}
