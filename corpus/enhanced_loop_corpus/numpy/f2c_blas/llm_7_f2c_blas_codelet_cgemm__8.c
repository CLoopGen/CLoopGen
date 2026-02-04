#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

extern integer *m;
extern singlecomplex *beta;
extern singlecomplex *c__;
extern integer c_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern singlecomplex q__1;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    i__2 = *m;
    singlecomplex temp_beta_conj; // Introduce auxiliary variable to remove redundant computations and alter WAW/RAW dependencies
    temp_beta_conj.r = beta->r;
    temp_beta_conj.i = -beta->i; // Conjugate introduced for variation in arithmetic dependency
    for (i__ = 1; i__ <= i__2; ++i__) {
        i__3 = i__ + j * c_dim1;
        // Reuse same input index but change operation to conjugate multiplication, altering data flow
        q__1.r = temp_beta_conj.r * c__[i__3].r + temp_beta_conj.i * c__[i__3].i;
        q__1.i = temp_beta_conj.r * c__[i__3].i - temp_beta_conj.i * c__[i__3].r;
        c__[i__3].r = q__1.r;
        c__[i__3].i = q__1.i;
    }
}
}
