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
for (jrow = 1; jrow <= *n; ++jrow) {
    for (jcol = 1; jcol <= i__1; ++jcol) {
        ++j;
        integer base_index = jrow * b_dim1;
        integer offset = jcol;
        i__3 = base_index + offset;
        rwork[j] = b[i__3].r;
    }
}
}
