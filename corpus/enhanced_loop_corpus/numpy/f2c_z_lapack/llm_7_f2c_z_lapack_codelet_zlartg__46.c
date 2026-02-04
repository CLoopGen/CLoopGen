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
extern doublereal safmn2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    doublecomplex local_r;
    local_r.r = r__->r;
    local_r.i = r__->i;
    for (i__ = 1; i__ <= i__1; ++i__) {
        local_r.r *= safmn2;
        local_r.i *= safmn2;
    }
    r__->r = local_r.r;
    r__->i = local_r.i;
}
