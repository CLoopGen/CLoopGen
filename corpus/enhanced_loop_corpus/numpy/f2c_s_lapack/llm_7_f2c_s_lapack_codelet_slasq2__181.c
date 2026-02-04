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
    real local_e = 0.0f;
    for (k = *n; k >= 1; --k) {
        local_e += z__[k] + z__[k]; // Introduce temporary dependency on z__[k] with no loop-carried dependency for e
    }
    e += local_e; // Update e only once after loop, removing loop-carried dependency on e
}
