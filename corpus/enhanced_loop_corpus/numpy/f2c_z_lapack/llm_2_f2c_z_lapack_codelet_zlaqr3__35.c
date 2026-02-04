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

extern doublecomplex *sh;
extern doublecomplex *t;
extern integer t_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer infqr;
extern integer kwtop;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing sh and t with non-unit stride, reorganize to access consecutive elements in sh
    // by precomputing base indices and using a sequential layout assumption.
    integer base_sh = kwtop + infqr;
    integer offset;
    for (i__ = 1; i__ <= i__1 - infqr; ++i__) {
        offset = i__ - 1;
        i__2 = base_sh + offset;
        i__3 = (infqr + i__) + (infqr + i__) * t_dim1;
        sh[i__2].r = t[i__3].r;
        sh[i__2].i = t[i__3].i;
    }
}
