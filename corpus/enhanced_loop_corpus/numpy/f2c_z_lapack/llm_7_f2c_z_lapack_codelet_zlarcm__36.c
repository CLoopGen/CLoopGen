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

extern integer *m;
extern doublecomplex *b;
extern doublereal *rwork;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        i__2 = *m;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = i__ + j * b_dim1;
            rwork[(j - 1) * *m + i__] = b[i__3].r + rwork[(j - 1) * *m + i__];
        }
    }
}
