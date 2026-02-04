#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

extern real *r__;
extern integer i__1;
extern integer i__;
extern real safmn2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real local_val = *r__;
    for (i__ = 1; i__ <= i__1; ++i__) {
        local_val = local_val * safmn2;
        *r__ = local_val; // WAW and RAW dependency introduced per iteration
    }
}
