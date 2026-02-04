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
extern integer *k;
extern doublecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__3;
extern integer j;
extern integer l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (*k + 1 <= i__1 && *m >= 1) {
    for (j = *k + 1; j <= i__1; ++j) {
        i__2 = j + j * a_dim1;
        a[i__2].r = 1. , a[i__2].i = 0.;
    }
    for (j = *k + 1; j <= i__1; ++j) {
        for (l = 1; l <= *m; ++l) {
            if (l != j) {
                i__3 = l + j * a_dim1;
                a[i__3].r = 0. , a[i__3].i = 0.;
            }
        }
    }
}
}
