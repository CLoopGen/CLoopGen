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
extern integer i__4;
extern doublecomplex z__1;
extern integer i__;
extern integer j;
extern doublereal mul;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= *m; ++i__) {
    for (j = i__; j <= i__1; ++j) {
        if (i__ > *m) continue;
        integer idx = i__ + j * a_dim1;
        a[idx].r = mul * a[idx].r;
        a[idx].i = mul * a[idx].i;
    }
}
}
