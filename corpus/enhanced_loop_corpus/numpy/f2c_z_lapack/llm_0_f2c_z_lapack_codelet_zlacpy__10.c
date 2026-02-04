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
extern doublecomplex *a;
extern doublecomplex *b;
extern integer a_dim1;
extern integer b_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__4;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j <= i__1; ++j) {
    for (integer k = 1; k <= *m; ++k) {
        i__2 = k + j * b_dim1;
        i__3 = k + j * a_dim1;
        b[i__2].r = a[i__3].r;
        b[i__2].i = a[i__3].i;
    }
}
}
