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
for (i__ = 1; i__ <= i__1 * 2; i__ += 2) {
    doublecomplex temp1, temp2;
    temp1.r = safmx2 * r__->r; temp1.i = safmx2 * r__->i;
    r__->r = temp1.r; r__->i = temp1.i;
    
    temp2.r = safmx2 * r__->r; temp2.i = safmx2 * r__->i;
    r__->r = temp2.r; r__->i = temp2.i;
}
}
