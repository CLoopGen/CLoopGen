#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *ihi;
extern real *tau;
extern integer i__1;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i__ = ((1) >= (*ihi) ? (1) : (*ihi)); i__ <= i__1; ++i__) {
        if (i__ % 2 == 0) {
            tau[i__] = 0.F;
        }
    }
}
