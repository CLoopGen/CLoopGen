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
    // Variant 2: Strided Memory Access Pattern
    // Modify access to t to use a fixed stride independent of loop index arithmetic,
    // simulating blocked or strided traversal assuming t is accessed column-wise with padding.
    integer j, t_index;
    for (j = 0; j < i__1 - infqr; ++j) {
        i__ = infqr + 1 + j;
        i__2 = kwtop + i__ - 1;
        // Simulate strided access: assume effective index increases by (t_dim1 + 1)
        t_index = (infqr + 1) * (t_dim1 + 1) + j * (t_dim1 + 1);
        sh[i__2].r = t[t_index].r;
        sh[i__2].i = t[t_index].i;
    }
}
