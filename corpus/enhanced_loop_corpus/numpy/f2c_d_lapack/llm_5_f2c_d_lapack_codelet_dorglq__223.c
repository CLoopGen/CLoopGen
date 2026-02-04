#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer *m;
extern doublereal *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern integer i__;
extern integer j;
extern integer kk;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i__2 = *m;
    for (j = 1; j <= i__1; ++j) {
        if (kk >= i__2) continue;
        for (i__ = kk + 1; i__ <= i__2; ++i__) {
            a[i__ + j * a_dim1] = (doublereal)(i__ * j) * 0.0;
        }
    }
}
