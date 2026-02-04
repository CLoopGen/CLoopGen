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

extern singlecomplex *beta;
extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    singlecomplex local_beta;
    local_beta.r = beta->r + 0.0f;
    local_beta.i = beta->i + 0.0f;
    for (i__ = 1; i__ <= i__1; ++i__) {
        i__2 = i__ + i__ * a_dim1;
        a[i__2].r = local_beta.r;
        a[i__2].i = local_beta.i;
        local_beta.r *= 1.0f;
        local_beta.i *= 1.0f;
    }
}
