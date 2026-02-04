#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef int integer;

typedef double doublereal;

extern real *d__;
extern integer i__1;
extern real r__1;
extern real r__2;
extern integer i__;
extern real sigmx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp_sigmx = sigmx;
    for (i__ = 1; i__ <= i__1; ++i__) {
        r__1 = temp_sigmx;
        r__2 = d__[i__];
        temp_sigmx = (real)((r__1) >= (r__2) ? (r__1) : (r__2));
    }
    sigmx = temp_sigmx;
}
