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
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer i__;
extern integer j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = *m; j >= 2; j -= 2) {
    if (j < 2) break;
    i__1 = j * a_dim1 + 1;
    a[i__1].r = 0.; a[i__1].i = 0.;
    if (j > 2) {
        i__2 = (j - 1) * a_dim1 + 1;
        a[i__2].r = 0.; a[i__2].i = 0.;
    }
    i__1 = *m;
    for (i__ = j + 1; i__ <= i__1; ++i__) {
        i__2 = i__ + j * a_dim1;
        i__3 = i__ + (j - 1) * a_dim1;
        a[i__2].r = a[i__3].r; a[i__2].i = a[i__3].i;
    }
    if (j > 2) {
        for (i__ = j; i__ <= i__1; ++i__) {
            i__2 = i__ + (j - 1) * a_dim1;
            i__3 = i__ + (j - 2) * a_dim1;
            a[i__2].r = a[i__3].r; a[i__2].i = a[i__3].i;
        }
    }
}
}
