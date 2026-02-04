#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

extern doublecomplex *r__;
extern integer i__1;
extern doublecomplex z__1;
extern integer i__;
extern doublereal safmx2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    doublereal temp_r = r__->r;
    doublereal temp_i = r__->i;
    z__1.r = safmx2 * temp_r;
    z__1.i = safmx2 * temp_i;
    r__->r = z__1.r;
    r__->i = z__1.i;
}
}
