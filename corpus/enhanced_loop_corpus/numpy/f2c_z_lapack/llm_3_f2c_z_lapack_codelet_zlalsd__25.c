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
// Modify memory access pattern to strided access: process every second column, then fill in
for (jcol = 1; jcol <= i__1; jcol += 2) {
    i__2 = *n;
    for (jrow = 1; jrow <= i__2; ++jrow) {
        ++j;
        i__3 = jrow + jcol * b_dim1;
        rwork[j] = b[i__3].r;
    }
}
// Second pass for remaining odd columns (if any)
for (jcol = 2; jcol <= i__1; jcol += 2) {
    i__2 = *n;
    for (jrow = 1; jrow <= i__2; ++jrow) {
        ++j;
        i__3 = jrow + jcol * b_dim1;
        rwork[j] = b[i__3].r;
    }
}
}
