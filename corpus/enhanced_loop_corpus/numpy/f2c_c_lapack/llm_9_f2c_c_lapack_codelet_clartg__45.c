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
extern real safmx2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; i__ += 2) {
    q__1.r = safmx2 * r__->r + safmx2 * r__->i;
    q__1.i = safmx2 * r__->i - safmx2 * r__->r;
    r__->r = q__1.r;
    r__->i = q__1.i;
    if (i__ + 1 <= i__1) {
        singlecomplex temp;
        temp.r = safmx2 * (r__->r + r__->i);
        temp.i = safmx2 * (r__->i - r__->r);
        r__++;
        r__->r = temp.r;
        r__->i = temp.i;
    }
}
}
