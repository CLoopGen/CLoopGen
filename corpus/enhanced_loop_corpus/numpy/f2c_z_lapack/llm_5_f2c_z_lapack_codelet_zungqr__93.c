#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

typedef int integer;

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
    for (j = kk + 1; j <= i__1; ++j) {
        i__2 = (kk > 0) ? kk : 0;
        if (i__2 <= 0) continue;
        for (i__ = 1; i__ <= i__2; ++i__) {
            i__3 = i__ + j * a_dim1;
            if (i__3 >= 0) {
                a[i__3].r = 0.0;
                a[i__3].i = 0.0;
            }
        }
    }
}
