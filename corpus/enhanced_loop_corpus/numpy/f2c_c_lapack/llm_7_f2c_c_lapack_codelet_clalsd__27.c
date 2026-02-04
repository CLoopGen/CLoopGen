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

extern integer *n;
extern singlecomplex *b;
extern real *rwork;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer j;
extern integer jcol;
extern integer jrow;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    real temp;
    for (jcol = 1; jcol <= i__1; ++jcol) {
        i__2 = *n;
        temp = 0.0f;
        for (jrow = 1; jrow <= i__2; ++jrow) {
            i__3 = jrow + jcol * b_dim1;
            temp += b[i__3].r; // Introduce accumulation (loop-carried RAW dependency)
        }
        rwork[jcol] = temp; // Store accumulated result per column
    }
}
