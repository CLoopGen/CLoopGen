#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

extern singlecomplex *r__;
extern integer i__1;
extern singlecomplex q__1;
extern integer i__;
extern real safmn2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    real temp_r = r__->r;
    real temp_i = r__->i;
    q__1.r = safmn2 * temp_r;
    q__1.i = safmn2 * temp_i;
    r__->r = q__1.r;
    r__->i = q__1.i;
}
}
