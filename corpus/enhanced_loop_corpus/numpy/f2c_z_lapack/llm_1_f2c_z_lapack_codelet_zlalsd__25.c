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
    for (jcol = 1; jcol <= i__1 && jrow <= i__2; ++jcol) { // Merged nested loops into a single loop (decreased nesting depth)
        i__2 = *n;
        jrow = 1;
        do {
            ++j;
            i__3 = jrow + jcol * b_dim1;
            rwork[j] = b[i__3].r;
            ++jrow;
        } while (jrow <= i__2);
    }
}
