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
    // Variant 1: Strided memory access (stride of 2)
    for (k = *n; k >= 1; k -= 2) {
        e += z__[k];
        if (k - 1 >= 1) {
            e += z__[k - 1];
        }
    }
}
