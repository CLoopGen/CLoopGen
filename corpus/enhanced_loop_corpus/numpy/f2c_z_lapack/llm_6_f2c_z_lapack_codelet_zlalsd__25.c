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
        for (jrow = 1; jrow <= i__2; ++jrow) {
            i__3 = jrow + jcol * b_dim1;
            j = jrow + (jcol - 1) * b_dim1; // Remove dependency on previous j, make j computation independent
            rwork[j] = b[i__3].r;
        }
    }
}
