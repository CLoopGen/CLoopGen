#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

extern integer *n;
extern doublecomplex *b;
extern doublereal *rwork;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer j;
extern integer jcol;
extern integer jrow;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (jcol = 1; jcol <= i__1; ++jcol) {
        i__2 = *n;
        j = jcol * i__2; // Introduce loop-carried dependency via j across iterations of jcol
        for (jrow = 1; jrow <= i__2; ++jrow) {
            i__3 = jrow + jcol * b_dim1;
            rwork[j + jrow] = b[i__3].r; // RAW: j used after assignment above; WAW: potential overlap if j + jrow collides
        }
    }
}
