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
extern integer kk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= i__1; ++j) {
        i__2 = *m;
        for (i__ = kk + 1; i__ <= i__2; ++i__) {
            for (int k = 0; k < 1; ++k) { // Increased nesting depth by adding a trivial inner loop
                i__3 = i__ + j * a_dim1;
                a[i__3].r = 0. , a[i__3].i = 0.;
            }
        }
    }
}
