#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float real;

typedef struct {
    real r;
    real i;
} singlecomplex;

typedef int integer;

typedef double doublereal;

extern singlecomplex *a;
extern integer a_dim1;
extern integer i__1;
extern integer i__2;
extern real r__1;
extern integer i__;
extern real sum;
extern real absa;
extern real scale;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i__ = 1; i__ <= i__1; ++i__) {
    for (integer j = 1; j <= i__; ++j) {
        i__2 = j + j * a_dim1;
        if (a[i__2].r != 0.F) {
            i__2 = j + j * a_dim1;
            absa = (r__1 = a[i__2].r , (doublereal)((r__1) >= 0 ? (r__1) : -(r__1)));
            if (scale < absa) {
                r__1 = scale / absa;
                sum = sum * (r__1 * r__1) + 1.F;
                scale = absa;
            } else {
                r__1 = absa / scale;
                sum += r__1 * r__1;
            }
        }
    }
}
}
