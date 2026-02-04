#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer i__1;
extern integer i__;
extern real b1;
extern real d1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real local_d1 = d1;
    for (i__ = 1; i__ <= i__1; ++i__) {
        local_d1 = local_d1 + b1 * i__;
    }
    d1 = local_d1;
}
